import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline()

n = ni()
k = ni()

ans = 99999999999999999999999
for i in range(1<<n):
    v = 1
    for j in range(n):
        if i>>j&1:
            v *= 2
        else:
            v += k
    ans = min(ans, v)
print(ans)

