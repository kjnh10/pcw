import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline()

n = ni()
x = []
for i in range(n+1):
    if i == 0:
        x.append(2)
    if i == 1:
        x.append(1)
    if i >= 2:
        x.append(x[-2] + x[-1])
print(x[-1])