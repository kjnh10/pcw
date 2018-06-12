import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline()

n = ni()

ans = 0
for i in range(n):
    l,r = na()
    ans += r-l+1
print(ans)

