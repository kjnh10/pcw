def dijkstra(V, edges, root):
    import heapq

    visited = [False] * V
    nodes = [[] for i in range(V)]
    cost = [[] for i in range(V)]

    for e in edges:
        s, t, d = e
        nodes[s].append(t)
        cost[s].append(d)

    dist = [float('inf')] * V
    dist[root] = 0

    h = [(0, root)]
    while h:
        c, v = heapq.heappop(h)
        if visited[v]:
            continue
        visited[v] = True
        for i in range(len(nodes[v])):
            t = nodes[v][i]
            nc = c + cost[v][i]
            if dist[t] > nc:
                dist[t] = nc
                heapq.heappush(h, (nc, t))
    return dist

N, M, T = map(int, input().split())
A = list(map(int, input().split()))
edges = []
edges_rev = []
for i in range(M):
    a, b, c = map(int, input().split())
    edges.append((a - 1, b - 1, c))
    edges_rev.append((b - 1, a - 1, c))
dist = dijkstra(N, edges, 0)
dist_rev = dijkstra(N, edges_rev, 0)
max_v = 0
for i in range(N):
    max_v = max(max_v, (T - dist[i] - dist_rev[i]) * A[i])
print(max_v)
