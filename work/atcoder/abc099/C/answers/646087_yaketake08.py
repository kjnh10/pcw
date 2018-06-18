N = int(input())
dp = [10**9]*(N+1)
dp[0] = 0
for i in range(N):
    j = 1
    while i+6**j <= N:
        dp[i+6**j] = min(dp[i+6**j], dp[i] + 1)
        j += 1
    j = 1
    while i+9**j <= N:
        dp[i+9**j] = min(dp[i+9**j], dp[i] + 1)
        j += 1

print(min(dp[i] + N-i for i in range(N+1)))



