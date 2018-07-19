import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline()

n = ni()
g = []
for i in range(n+1): g.append([])

for i in range(n-1):
    a, b, c = na()
    g[a].append((b,c))
    g[b].append((a,c))

q,k = na()

def dfs(cur, pre, g, par, dw, w):
    dw[cur] = w
    par[cur] = pre
    for e in g[cur]:
        if e[0] != pre:
            dfs(e[0], cur, g, par, dw, w + e[1])

par = [-1] * (n+2)
dw = [-1] * (n+2)
from queue import Queue
qs = Queue()
qs.put(k)
dw[k] = 0

while not qs.empty():
    cur = qs.get()
    for e in g[cur]:
        if e[0] != par[cur]:
            par[e[0]] = cur
            dw[e[0]] = dw[cur] + e[1]
            qs.put(e[0])


# dfs(k, -1, g, par, dw, 0)

for z in range(q):
    x, y = na()
    print(dw[x] + dw[y])

