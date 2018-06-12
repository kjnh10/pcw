from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt
from collections import deque
from bisect import bisect, bisect_left, bisect_right
INF = float("inf")


def dfs(parent, now, used, graph):
    is_tree = True
    for node in graph[now]:
        if node == parent:
            continue
        if used[node]:
            is_tree = False
            continue
        used[node] = 1
        is_tree &= dfs(now, node, used, graph)
    return is_tree


def main():
    N, M = map(int, input().split())
    graph = defaultdict(list)
    for _ in range(M):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        graph[u].append(v)
        graph[v].append(u)

    ans = 0
    used = [0] * N
    for node in range(N):
        if not used[node]:
            used[node] = 1
            ans += dfs(-1, node, used, graph)

    print(ans)


if __name__ == '__main__':
    main()
