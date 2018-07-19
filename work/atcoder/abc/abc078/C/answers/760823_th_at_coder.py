import sys

n, m = list(map(int, sys.stdin.readline().strip().split(" ")))

one_t = 100 * (n - m) + 1900 * m

num = 2**m

print(str(one_t * num))


