import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline()

a = [0] * 100005

isp = [1] * 100005
isp[0] = isp[1] = 0
for i in range(2, 100005):
    if isp[i]:
        for j in range(i*i, 100005, i):
            isp[j] = 0
for i in range(3, 100005, 2):
    if isp[i] and isp[(i+1)//2]:
        a[i] = 1
for i in range(1, 100004):
    a[i+1] += a[i]

q = ni()
for i in range(q):
    l, r = na()
    print(a[r] - a[l-1])
