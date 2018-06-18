from heapq import heappop, heappush
from itertools import permutations


def solve(links, rs):
    r = len(rs)
    dists = [[-1] * r for _ in range(r)]
    r_dict = {ri: i for i, ri in enumerate(rs)}
    for ri in rs:
        dists_r = dists[r_dict[ri]]
        visited = set()
        queue = [(0, ri)]
        r_cnt = 0
        while queue:
            cost, node = heappop(queue)
            if node in visited:
                continue
            if node in r_dict:
                dists_r[r_dict[node]] = cost
                r_cnt += 1
                if r_cnt == r:
                    break
            visited.add(node)
            for c, a in links[node]:
                if a not in visited:
                    heappush(queue, (cost + c, a))
    ans = 1e9
    for p in permutations(range(r)):
        tmp = sum(dists[r1][r2] for r1, r2 in zip(p, p[1:]))
        ans = min(ans, tmp)
    return ans


n, m, r = map(int, input().split())
rs = [i - 1 for i in map(int, input().split())]
links = [set() for _ in range(n)]
for a, b, c in (map(int, input().split()) for _ in range(m)):
    a -= 1
    b -= 1
    links[a].add((c, b))
    links[b].add((c, a))

print(solve(links, rs))
