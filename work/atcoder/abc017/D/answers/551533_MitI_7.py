from collections import defaultdict
from itertools import product, groupby
from math import pi
from collections import deque
from bisect import bisect, bisect_left, bisect_right
INF = 10 ** 10


def main():
    N, M = map(int, input().split())
    dp = [0] * (N + 2)
    S = [0] * (N + 2)

    dp[1] = S[1] = 1
    MOD = 1000000007
    prev = [1] * 100003

    le = 1
    for i in range(N):
        f = int(input())
        le = max(le, prev[f])

        dp[i + 2] = (S[i + 1] - S[le - 1] + MOD) % MOD
        S[i + 2] = (S[i + 1] + dp[i + 2]) % MOD
        prev[f] = i + 2

    print(((dp[-1] % MOD) + MOD) % MOD)


if __name__ == '__main__':
    main()
