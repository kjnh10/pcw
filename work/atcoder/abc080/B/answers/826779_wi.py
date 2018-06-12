import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline()

n = ni()
f = 0
for x in str(n):
    f += ord(x) - ord('0')
print("Yes" if n % f == 0 else "No")
