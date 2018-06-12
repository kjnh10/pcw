n = int(input())
edges = [set() for _ in range(n)]
matched = [-1] * n
ab = [list(map(int, input().split())) for _ in range(n)]
cd = [list(map(int, input().split())) for _ in range(n)]
for j, (c, d) in enumerate(cd):
    for i, (a, b) in enumerate(ab):
        if a < c and b < d:
            edges[i].add(j)


def dfs(v, visited):
    for u in edges[v]:
        if u in visited:
            continue
        visited.add(u)
        if matched[u] == -1 or dfs(matched[u], visited):
            matched[u] = v
            return True
    return False


print(sum(dfs(s, set()) for s in range(n)))
