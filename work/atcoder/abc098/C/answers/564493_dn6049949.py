n = int(input())
s = input()
dp = [float("inf") for i in range(n)]
dp[0] = 0
for i in range(1,n):
    if s[i] == "E":
        dp[0] += 1
for i in range(1,n):
    dp[i] = dp[i-1]
    if s[i-1] == "W":
        dp[i] += 1
    if s[i] == "E":
        dp[i] -= 1
print(min(dp))