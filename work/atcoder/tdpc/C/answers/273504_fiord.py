import sys
import math
sys.setrecursionlimit(10000)


def calc(rp, rq):
    a = (rq - rp) / 400.0
    return 1 / (1 + 10**a)


k = int(input())
n = 2**k
r = []
for i in range(n):
    r.append(int(input()))
dp = [[0] * (k + 1) for i in range(n)]
for i in range(n):
    dp[i][0] = 1.0
base = 1
for t in range(k):
    for i in range(n):
        for j in range(base):
            to = (base | j) ^ i
            dp[i][t + 1] += dp[i][t] * dp[to][t] * calc(r[i], r[to])
    base *= 2
for i in range(n):
    print("{0:f}".format(dp[i][k]))
