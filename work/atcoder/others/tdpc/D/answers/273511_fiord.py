import sys
import math
sys.setrecursionlimit(10000)

n, d = map(int, input().split())
two = 0
while d % 2 == 0:
    two += 1
    d /= 2
three = 0
while d % 3 == 0:
    three += 1
    d /= 3
five = 0
while d % 5 == 0:
    five += 1
    d /= 5
if d != 1:
    print(0)
    exit(0)
dp = [[[[0] * (five + 1) for i in range(three + 1)]
       for j in range(two + 1)] for k in range(n + 1)]
dp[0][0][0][0] = 1.0
for i in range(n):
    for j in range(two + 1):
        for k in range(three + 1):
            for l in range(five + 1):
                if dp[i][j][k][l] == 0:
                    continue
                add = dp[i][j][k][l] / 6.0
                # 1
                dp[i + 1][j][k][l] += add
                # 2
                dp[i + 1][min(two, j + 1)][k][l] += add
                # 3
                dp[i + 1][j][min(three, k + 1)][l] += add
                # 4
                dp[i + 1][min(j + 2, two)][k][l] += add
                # 5
                dp[i + 1][j][k][min(l + 1, five)] += add
                # 6
                dp[i + 1][min(j + 1, two)][min(three, k + 1)][l] += add
print("{0:f}".format(dp[n][two][three][five]))
