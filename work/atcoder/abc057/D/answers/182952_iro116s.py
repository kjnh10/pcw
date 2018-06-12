N, A, B = map(int, input().split())
v = list(map(int, input().split()))

dp = [[-1 for _ in range(N + 1)] for _ in range(N + 1)]
cnt = [[0 for _ in range(N + 1)] for _ in range(N + 1)]
dp[0][0] = 0
cnt[0][0] = 1

for i in range(N):
    for j in range(N - 1, -1, -1):
        if dp[i][j] == -1:
            continue
        dp[i+1][j] = dp[i][j]
        cnt[i+1][j] = cnt[i][j]

        ncost = dp[i][j] + v[i]
        if dp[i+1][j+1] < ncost:
            dp[i+1][j+1] = ncost
            cnt[i+1][j+1] = cnt[i][j]
        elif dp[i+1][j+1] == ncost:
            cnt[i+1][j+1] += cnt[i][j]

maxVal = 0
maxCnt = 0
for i in range(A, B + 1):
    if maxVal < dp[N][i] / i:
        maxVal = dp[N][i] / i
        maxCnt = cnt[N][i]
    elif maxVal == dp[N][i] / i:
        maxCnt += cnt[N][i]

print(maxVal)
print(maxCnt)