import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline()

def gcd(a, b):
    while(b > 0):
        c = a % b
        a = b; b = c
    return a

n = ni()
g = 0
for i in range(n):
    v = ni()
    if g == 0:
        g = v
    else:
        g = g//gcd(g,v)*v
print(g)