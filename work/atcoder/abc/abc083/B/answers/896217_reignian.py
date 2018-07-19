import sys
n, a, b = map(int, sys.stdin.readline().split())

def sumDigits(x):
    s = 0
    while x > 0:
        s += x % 10
        x = x // 10
    return s

s = 0
for i in range(1, n+1):
    if a <= sumDigits(i) <= b:
        s += i

print(s)