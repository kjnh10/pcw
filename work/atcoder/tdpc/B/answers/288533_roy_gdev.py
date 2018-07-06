a, b = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

dp = [[0 for j in range(b+1)] for i in range(a+1)]

for i in range(1,a+1):
	num_of_taken_items = a + b - i
	if num_of_taken_items % 2 == 0: # F
		dp[i][0] = dp[i-1][0] + A[a-i]
	else:
		dp[i][0] = dp[i-1][0]

for j in range(1,b+1):
	num_of_taken_items = a + b - j
	if num_of_taken_items % 2 == 0: # F
		dp[0][j] = dp[0][j-1] + B[b-j]
	else:
		dp[0][j] = dp[0][j-1]

for i in range(1,a+1):
	for j in range(1,b+1):
		num_of_taken_items = a + b - i - j
		if num_of_taken_items % 2 == 0: # F
			dp[i][j] = max(dp[i-1][j] + A[a-i], dp[i][j-1] + B[b-j])
		else:
			dp[i][j] = min(dp[i-1][j], dp[i][j-1])

print(dp[a][b])