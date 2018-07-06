n = int(input())
p = list(map(int, input().split()))
m = max(p) + 1
m *= n
dp = [0 for i in range(m)]
dp[0] = 1
for i in range(n):
    for j in reversed(range(p[i], m)):
        if dp[j - p[i]] == 0:
            continue
        dp[j] = 1
ret = sum(dp)
print(ret)
