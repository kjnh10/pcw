from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt
from collections import deque
from bisect import bisect, bisect_left, bisect_right
INF = float("inf")
MOD = 10 ** 9 + 7


def factorial_mod(n, mod):
    ans = 1
    for i in range(1, n + 1):
        ans = ans * i % mod
    return ans % mod


def main():
    N = int(input())
    T_list = list(sorted([int(input()) for _ in range(N)]))

    penalty = 0
    for i in range(N):
        penalty += T_list[i] * (N - i)

    c = Counter(T_list)
    ans = 1
    for k, v in c.items():
        ans = (ans * factorial_mod(v, MOD)) % MOD

    print(penalty)
    print(ans % MOD)


if __name__ == '__main__':
    main()
