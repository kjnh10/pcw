N = int(input())
p = [0] + [int(s) for s in input().split()]
p_score = sum(p)
dp = [[0] * (p_score+1) for i in range(N+1)]

dp[0][0] = 1
for i in range(1, N+1):
    for j in range(p_score+1):
        if dp[i-1][j] == 1:
            dp[i][j+p[i]] = 1
            dp[i][j] = 1
print(sum(dp[N]))