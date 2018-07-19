from heapq import heappop, heappush
N = int(input())
edges = [[]*N for _ in [None]*N]
for _ in [None]*(N-1):
    a, b, c = map(int, input().split())
    edges[a-1].append((b-1, c))
    edges[b-1].append((a-1, c))

Q, K = map(int, input().split())

def dijkstra(n, edges, start):
    inf = float("inf")
    vertices = [inf] * n
    vertices[start] = 0
    q, rem = [(0, start)], n - 1

    while q and rem:
        cost, v = heappop(q)
        if vertices[v] < cost:
            continue
        rem -= 1

        for dest, _cost in edges[v]:
            newcost = cost + _cost
            if vertices[dest] > newcost:
                vertices[dest] = newcost
                heappush(q, (newcost, dest))

    return vertices

costs = dijkstra(N, edges, K-1)

result = []
for _ in [None]*Q:
    x, y = map(int, input().split())
    result.append(costs[x-1] + costs[y-1])

for x in result:
    print(x)