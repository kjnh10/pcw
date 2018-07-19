import sys

stdin = sys.stdin


def na(): return map(int, stdin.readline().split())


def ns(): return stdin.readline().strip()

n = int(ns())
i = 1
mi = n
while i*i <= n:
    if n % i == 0:
        x = n//i
        mi = min(mi, x)
    i += 1
print(len(str(mi)))
