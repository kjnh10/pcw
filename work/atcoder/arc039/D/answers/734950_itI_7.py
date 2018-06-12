from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt
from collections import deque
from bisect import bisect, bisect_left, bisect_right
INF = float("inf")
MOD = 1000000007

class Combination:
    def __init__(self, n, mod):
        assert 0 < n
        self.mod = mod
        self.fact = [1] * (n + 1)
        self.inv = [1] * (n + 1)
        for i in range(1, len(self.fact)):
            self.fact[i] = (i * self.fact[i - 1]) % self.mod
            self.inv[i] = pow(self.fact[i], self.mod - 2, self.mod)

    def nCr(self, n, k):
        # assert 0 < n < len(self.fact) and 0 <= k
        a = self.fact[n]
        b = (self.inv[k] * self.inv[n - k]) % self.mod
        return a * b % self.mod


def main():
    N, K = map(int, input().split())

    comb = Combination(700, MOD)

    if N == K:
        print(1)
    elif N <= K:
        r = K % N
        print(comb.nCr(N, r))
    else:
        print(comb.nCr(N + K - 1, K))


if __name__ == '__main__':
    main()
