N = int(input())
p = list(map(int,input().split()))

# N = 3
# p = [2,5,8]
# dp[i][j] = i問目までに説いたときの点数がjに成ることがあるかどうか
dp = [[0 for i in range(sum(p)+1)] for j in range(N+1)]
dp[0][0] = 1

for i in range(1,N+1):
    for j in range(sum(p)+1):
        if dp[i-1][j] == 1:
            dp[i][j] = 1
            dp[i][j+p[i-1]] = 1


print(sum(dp[N]))





