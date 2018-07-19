import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline()

n = ni()
t = na()
v = na()

bound = [0] * (n+1)
for i in range(n-1):
    bound[i+1] = min(v[i], v[i+1], bound[i] + t[i])
for i in range(n-1,0,-1):
    bound[i] = min(bound[i], v[i], v[i-1], bound[i+1] + t[i])

ans = 0
for i in range(n):
    l = bound[i]
    r = bound[i+1]
    # l + x = r + t - x
    # x = (r-l+t)/2
    x = (r-l+t[i])/2
    if l + x <= v[i]:
        ans += (l + (l + x)) * x / 2 + (l + x + r) * (t[i] - x) / 2
    else:
        ans += (v[i] + l) * (v[i] - l) / 2 + (v[i] + r) * (v[i] - r) / 2
        ans += (t[i] - (v[i] - l) - (v[i] - r)) * v[i]
print("{:.14f}".format(ans))
