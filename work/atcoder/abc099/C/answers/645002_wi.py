import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline()

n = ni()

dp = [99999999]*(n+1)
dp[0] = 0
for i in range(1, n+1):
    dp[i] = dp[i-1] + 1
    k = 6
    while i-k >= 0:
        dp[i] = min(dp[i], dp[i-k]+1)
        k *= 6
    k = 9
    while i-k >= 0:
        dp[i] = min(dp[i], dp[i-k]+1)
        k *= 9
print(dp[n])

