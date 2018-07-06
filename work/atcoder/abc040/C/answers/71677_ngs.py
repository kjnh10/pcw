N = int(input())
a = list(map(int, input().split()))

dp = [0 for k in range(N)]
dp[0] = 0
dp[1] = abs(a[1]-a[0])

for k in range(2,N):
    if dp[k-1] + abs(a[k]-a[k-1]) < dp[k-2] + abs(a[k]-a[k-2]):
        dp[k] = dp[k-1] + abs(a[k]-a[k-1])
    else:
        dp[k] = dp[k-2] + abs(a[k]-a[k-2])

print(dp[N-1])