N = int(input())
dp = [999] * (300 + 1)
dp[0] = 0
for ng in [int(input()) for _ in range(3)]:
    dp[ng] = -1

if dp[N] == -1:
    print('NO')
    import sys

    sys.exit()

for i in range(1, N + 1):
    if dp[i] == -1:
        continue
    for j in range(1, 4):
        if dp[i - j] == -1:
            continue
        v = 0
        if i - j >= 0:
            v = dp[i - j]
        dp[i] = min(v + 1, dp[i])

if dp[N] <= 100:
    print('YES')
else:
    print('NO')

# print(dp)
