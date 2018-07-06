A,B = list(map(int,input().split()))
a = list(map(int,input().split()))
b = list(map(int,input().split()))

# A,B = 4,3
# a = [2,4,5,4]
# b = [2,8,3]

# A,B = 1,3
# a = [1]
# b = [2,9,9]


# dp[i][j] = 左からi右からjとったときの最高点

dp = [[0 for j in range(B+1)] for i in range(A+1)]

for i in range(A)[::-1]:
	if (B+i)%2 == 0:
		dp[i][B] = dp[i+1][B] + a[i]
	else:
		dp[i][B] = dp[i+1][B]
for j in range(B)[::-1]:
	if (A+j)%2 == 0:
		dp[A][j] = dp[A][j+1] + b[j]
	else:
		dp[A][j] = dp[A][j+1]

for i in range(A)[::-1]:
	for j in range(B)[::-1]:
		if (i+j)%2 == 0:
			dp[i][j] = max(dp[i+1][j]+a[i], dp[i][j+1]+b[j])
		else:
			dp[i][j] = min(dp[i+1][j], dp[i][j+1])


print(dp[0][0])

# for i in dp:
# 	print(i)




