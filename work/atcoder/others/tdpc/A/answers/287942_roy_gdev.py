n = int(input())
P = list(map(int, input().split()))

max_score = n * 100
dp = [[False for j in range(max_score+1)] for i in range(n+1)]

for i in range(n+1):
	dp[i][0] = True

for i in range(1,n+1):
	for j in range(1,max_score+1):
		dp[i][j] = dp[i-1][j]
		if P[i-1] <= j:
			dp[i][j] = dp[i][j] or dp[i-1][j-P[i-1]]


print(dp[n].count(True))