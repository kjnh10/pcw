import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline()

n = ni()
fs = []
for i in range(n):
    x = na()
    ptn = 0
    for j in range(10):
        ptn |= x[j]<<j
    fs.append(ptn)
ps = []
for i in range(n):
    ps.append(na())

def bct(x):
    ret = 0
    while x > 0:
        ret += x&1
        x >>=1
    return ret

ans = -9999999999999999
for i in range(1, 1024):
    s = 0
    for j in range(n):
        s += ps[j][bct(fs[j]&i)]
    ans = max(ans, s)
print(ans)
