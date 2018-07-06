import sys
sys.setrecursionlimit(10000)


def solve(i, j):
    if dp[i][j] != -1:
        return dp[i][j]
    if (i + j) & 1 == 0:
        dp[i][j] = 0
        if i < A:
            dp[i][j] = max(dp[i][j], solve(i + 1, j) + a[i])
        if j < B:
            dp[i][j] = max(dp[i][j], solve(i, j + 1) + b[j])
    else:
        dp[i][j] = 10**9
        if i < A:
            dp[i][j] = min(solve(i + 1, j), dp[i][j])
        if j < B:
            dp[i][j] = min(solve(i, j + 1), dp[i][j])
    return dp[i][j]


A, B = map(int, input().split())
a = list(map(int, input().split()))
dp = [[-1] * (B + 11) for i in range(A + 11)]
b = list(map(int, input().split()))
dp[A][B] = 0
print(solve(0, 0))
