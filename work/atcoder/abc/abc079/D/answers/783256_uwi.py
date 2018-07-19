import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline()

h, w = na()
g = []
for i in range(10):
    g.append(na())

for k in range(10):
    for i in range(10):
        for j in range(10):
            g[i][j] = min(g[i][j], g[i][k] + g[k][j])

ret = 0
for i in range(h):
    row = na()
    for v in row:
       if v >= 0:
           ret += g[v][1]
print(ret)