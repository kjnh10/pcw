N, K = map(int, input().split())
dp = [0]*N
dp[0] = 1
s = 1
MOD = 10**9 + 7
for i in range(2, N):
    dp[i] = s
    s += dp[i]
    if i >= K:
        s -= dp[i-K]
    s %= MOD
s -= dp[N-K]
print(s % MOD)