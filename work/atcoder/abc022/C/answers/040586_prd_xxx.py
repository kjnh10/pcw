import heapq
import time
N,M = map(int, input().split())
es = [[] for i in range(N)]
for i in range(M):
    u,v,l = map(int, input().split())
    u,v = u-1, v-1
    es[u].append((l,v))
    es[v].append((l,u))
 
started = time.time()
INF = float('inf')
ans = INF
for sd,sv in sorted(es[0]):
    if time.time() - started > 1.8: break
    visited = [0] * N
    q = [(sd,sv)]
    heapq.heapify(q)
    while q:
        d,v = heapq.heappop(q)
        visited[v] = 1
        if v == 0:
            ans = min(ans, d)
            break
        for l,to in es[v]:
            if visited[to] or (v,to) == (sv,0): continue
            heapq.heappush(q, (d+l,to))
 
print(-1 if ans == INF else ans)