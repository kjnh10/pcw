import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline()

n = ni()
a = na()
ans = 0
for i in a:
    while i % 2 == 0:
        i //= 2
        ans += 1
print(ans)
