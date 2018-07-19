import sys
from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt, ceil, floor
from collections import deque
from bisect import bisect, bisect_left, bisect_right
from string import ascii_lowercase
INF = float("inf")
sys.setrecursionlimit(10**7)

# 4近傍（右, 下, 左, 上）
dy = [0, -1, 0, 1]
dx = [1, 0, -1, 0]


def inside(y: int, x: int, H: int, W: int) -> bool: return 0 <= y < H and 0 <= x < W


def main():
    N = int(input())
    A = list(map(int, input().split()))

    ans = []

    t = A[:]
    a = min(A)
    a_idx = A.index(a)
    for i in range(N):
        t[i] += a
        if t[i] > 0:
            ans = []
            break
        else:
            if i != a_idx:
                ans.append((a_idx + 1, i + 1))

    if len(ans) != 0:
        ans.append((a_idx + 1, a_idx + 1))
        for i in range(N, 1, -1):
            ans.append((i, i - 1))
        print(len(ans))
        for a in ans:
            print(a[0], a[1])
        return

    t = A[:]
    a = max(A)
    a_idx = A.index(a)
    for i in range(N):
        t[i] += a
        if i != a_idx:
            ans.append((a_idx + 1, i + 1))
    ans.append((a_idx + 1, a_idx + 1))
    for i in range(1, N):
        ans.append((i, i + 1))
    print(len(ans))
    for a in ans:
        print(a[0], a[1])
    return

if __name__ == '__main__':
    main()
