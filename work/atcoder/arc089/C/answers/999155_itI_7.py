from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt
from collections import deque
from bisect import bisect, bisect_left, bisect_right
from string import ascii_lowercase
from functools import lru_cache
INF = float("inf")
import sys
sys.setrecursionlimit(10000)


def solve(N, l):
    nt, nx, ny = 0, 0, 0
    for i in range(len(l)):
        t, x, y = l[i]
        a = abs(x - nx) + abs(y - ny)
        k = t - nt
        if (k >= a and k % 2 == a % 2):
            pass
        else:
            return False
    return True


def main():
    
    N = int(input())
    l = []
    for i in range(0, N):
        t, x, y = map(int, input().split())
        l.append((t, x, y))
    print("Yes" if solve(N, l) else "No")


if __name__ == '__main__':
    main()
