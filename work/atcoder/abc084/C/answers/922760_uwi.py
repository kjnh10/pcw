import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline()

n = ni()
cs = []
ss = []
fs = []
for i in range(n-1):
    c, s, f = na()
    cs.append(c)
    ss.append(s)
    fs.append(f)

for i in range(n):
    t = 0
    for j in range(i, n-1):
        if t <= ss[j]:
            t = ss[j]
        else:
            t = (t + fs[j] - 1) // fs[j] * fs[j]
        t += cs[j]
    print(t)
