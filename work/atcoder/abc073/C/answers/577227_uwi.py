import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline()

n = ni()
s = set()
for i in range(n):
    x = ni()
    if x in s:
        s.remove(x)
    else:
        s.add(x)
print(len(s))