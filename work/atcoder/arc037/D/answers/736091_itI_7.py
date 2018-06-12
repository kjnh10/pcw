from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt
from collections import deque
from bisect import bisect, bisect_left, bisect_right
INF = float("inf")

is_tree = True
def dfs(parent, now, used, graph):
    global is_tree
    for n in graph[now]:
        if n == parent:
            continue
        if used[n]:
            is_tree = False
            continue
        used[n] = 1
        dfs(now, n, used, graph)


def main():
    N, M = map(int, input().split())
    graph = defaultdict(list)
    for _ in range(M):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        graph[u].append(v)
        graph[v].append(u)

    global is_tree
    ans = 0
    memo = [0] * N
    for node in range(N):
        if not memo[node]:
            is_tree = True
            used = [0] * N
            used[node] = 1
            dfs(-1, node, used, graph)
            ans += is_tree

            for i in range(N):
                memo[i] += used[i]

    print(ans)


if __name__ == '__main__':
    main()
