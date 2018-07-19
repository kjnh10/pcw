from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt
from collections import deque
from bisect import bisect, bisect_left, bisect_right
INF = float("inf")


def dfs(i, used, g, ng):
    for n in g[i]:
        if n not in used and (i, n) != ng and (n, i) != ng:
            used.add(n)
            dfs(n, used, g, ng)


def main():
    N, M = map(int, input().split())
    g = defaultdict(list)
    k = []
    for _ in range(M):
        a, b = map(int, input().split())
        g[a].append(b)
        g[b].append(a)
        k.append((a, b))

    ans = 0
    for a, b in k:
        used = set()
        dfs(1, used, g, (a, b))
        if len(used) != N:
            ans += 1
    print(ans)





if __name__ == '__main__':
    main()
