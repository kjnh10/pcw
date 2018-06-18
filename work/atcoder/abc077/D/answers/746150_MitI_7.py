from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt
from collections import deque
from bisect import bisect, bisect_left, bisect_right
from heapq import heappush, heappop
INF = float("inf")


def main():
    K = int(input())
    graph = defaultdict(list)
    for i in range(K):
        graph[i].append((1, (i + 1) % K))
        graph[i].append((0, (i * 10) % K))

    cost = [INF] * K
    cost[1] = 1
    que = deque()
    que.appendleft(1)
    while len(que) != 0:
        now = que.popleft()

        for c, node in graph[now]:
            new_cost = cost[now] + c
            if new_cost < cost[node]:
                cost[node] = new_cost
                if c == 0:
                    que.appendleft(node)
                else:
                    que.append(node)

    print(cost[0])


if __name__ == '__main__':
    main()
