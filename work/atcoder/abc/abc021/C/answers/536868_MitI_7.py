from collections import defaultdict
from itertools import product
from math import pi
from collections import deque
INF = 10 ** 10


def main():
    MOD = 10 ** 9 + 7
    N = int(input())
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    graph = defaultdict(list)
    for _ in range(int(input())):
        x, y = map(int, input().split())
        graph[x - 1].append(y - 1)
        graph[y - 1].append(x - 1)

    q = deque()
    q.append(a)
    cost = [INF] * N
    cost[a] = 0
    root = [0] * N
    root[a] = 1
    while q:
        s = q.popleft()
        now_root = root[s]
        now_cost = cost[s]
        for g in graph[s]:
            if now_cost + 1 > cost[g]:
                continue
            elif now_cost + 1 == cost[g]:
                root[g] += now_root
            elif now_cost + 1 < cost[g]:
                root[g] = now_root
                q.append(g)

            cost[g] = now_cost + 1
            root[g] %= MOD

    print(root[b])


if __name__ == '__main__':
    main()
