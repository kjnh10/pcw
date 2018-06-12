from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt
from collections import deque
from bisect import bisect, bisect_left, bisect_right
INF = float("inf")


def main():
    N, R = map(int, input().split())
    S = list(0 if x == "." else 1 for x in input())
    while len(S) != 0 and S[-1] == 1:
        S.pop(len(S) - 1)
    N = len(S)
    ans = 0
    now = 0
    right = max(0, N - R)
    while now < N:
        if S[now] == 0 or now == right:
            for i in range(now, min(N, now + R)):
                S[i] = 1
            ans += 1
            if now == right:
                break
        else:
            now += 1
            ans += 1

    print(ans)


if __name__ == '__main__':
    main()
