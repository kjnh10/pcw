import sys
from collections import Counter

def solve():
    N, K = map(int, input().split())
    cntr = Counter()

    for i in range(N):
        ai, bi = map(int, sys.stdin.readline().split())
        cntr[ai] += bi

    cntr = sorted(cntr.items())
    # print(cntr)

    cnt = 0

    for a, b in cntr:
        cnt += b

        if cnt >= K:
            print(a)
            return


if __name__ == '__main__':
    solve()