import sys

x = int(next(sys.stdin).strip())
n = x // (6 + 5)
r = x % (6 + 5)

if r == 0:
    print(n * 2)
elif r <= 6:
    print(n * 2 + 1)
else:
    print(n * 2 + 2)
