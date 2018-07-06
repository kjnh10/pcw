def dijk(g, s):
    n = len(g)
    import heapq
    h = []
    heapq.heappush(h, (0,s))
    d = [999999999999999] * n
    d[s] = 0
    while len(h) > 0:
        cur = heapq.heappop(h)
        if d[cur[1]] != cur[0]: continue
        ld = cur[0]
        for e in g[cur[1]]:
            nd = ld + e[1]
            if nd < d[e[0]]:
                d[e[0]] = nd
                heapq.heappush(h, (nd, e[0]))
    return d

import sys
stdin = sys.stdin


n,m,t=map(int,stdin.readline().split())
x = list(map(int,stdin.readline().split()))

g = []
ig = []
for i in range(n+1):
    g.append([])
    ig.append([])
for i in range(m):
    a,b,c = map(int,stdin.readline().split())
    g[a].append([b,c])
    ig[b].append([a,c])

df = dijk(g, 1)
db = dijk(ig, 1)
rmax = 0
for i in range(n):
    if df[i+1] + db[i+1] <= t:
        rmax = max(rmax, x[i] * (t-(df[i+1]+db[i+1])))

print(rmax)