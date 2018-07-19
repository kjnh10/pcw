import sys

stdin = sys.stdin
def na(): return map(int, stdin.readline().split())
def ns(): return stdin.readline().strip()


n,ma,mb = na()
abcs = []
for i in range(n):
    abcs.append(list(na()))
I = 9999999999
dp = [[I]*420 for _ in range(420)]
dp[0][0] = 0
sa = 1; sb = 1
for abc in abcs:
    for i in range(sa-1,-1,-1):
        for j in range(sb-1,-1,-1):
            dp[i+abc[0]][j+abc[1]] = min(dp[i+abc[0]][j+abc[1]], dp[i][j] + abc[2])
    sa += abc[0]
    sb += abc[1]
x = ma
y = mb
ret = I
while x < 420 and y < 420:
    ret = min(ret, dp[x][y])
    x += ma
    y += mb
if ret == I:
    print(-1)
else:
    print(ret)