import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline()

n = ni()
a = na()
f = [0]*8
sp = 0
for v in a:
    if v >= 3200:
        sp += 1
    else:
        f[v//400] = 1
if sum(f) > 0:
    print("{} {}".format(sum(f), sum(f)+sp))
else:
    print("{} {}".format(sum(f)+min(sp,1), sum(f)+sp))

