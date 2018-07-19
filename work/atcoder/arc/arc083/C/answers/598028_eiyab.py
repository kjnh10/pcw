a, b, c, d, e, f = map(int, input().split())

water_dp = [True] + [False for _ in range(100)]
suger_dp = [True] + [False for _ in range(f + 100)]

for i in range(0, 31):
    water_dp[i+a] = water_dp[i+a] or water_dp[i]
    water_dp[i+b] = water_dp[i+b] or water_dp[i]

for i in range(0, f+1):
    suger_dp[i+c] = suger_dp[i+c] or suger_dp[i]
    suger_dp[i+d] = suger_dp[i+d] or suger_dp[i]

ans = (0, 0, 0)

for i in range(1, 31):
    if not water_dp[i]:
        continue
    suger = 0
    for j in range(0, f):
        if suger_dp[j] and i*100 + j <= f and j <= e * i:
            suger = j
    if suger * 100 / (i*100 + suger) > ans[2]:
        ans = (i, suger, suger * 100 / (i*100 + suger))

if ans[0] != 0:
    print(ans[0]*100 + ans[1], ans[1])
else:
    print(100 * a, 0)