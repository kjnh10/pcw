from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt
from collections import deque
from bisect import bisect, bisect_left, bisect_right
INF = float("inf")

# 4近傍（右, 下, 左, 上）
dy = [0, -1, 0, 1]
dx = [1, 0, -1, 0]


def change(y, x, b, n):
    for i in range(4):
        ny, nx = y + dy[i], x + dx[i]
        b[ny][nx] -= n


def main():
    N, M = map(int, input().split())
    b = []
    for _ in range(N):
        b.append(list(map(int, list(input()))))
    ans = [[0] * M for _ in range(N)]

    for y in range(N - 2):
        for x in range(1, M - 1):
            n = b[y][x]
            ans[y + 1][x] += n
            change(y + 1, x, b, n)
    for line in ans:
        print(*line, sep="")


if __name__ == '__main__':
    main()
