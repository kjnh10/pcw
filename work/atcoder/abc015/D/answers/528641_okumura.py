W = int(input())
N,K =map(int, input().split())
dp =[[11000]*(5100) for i in range(51)  ]
dp[0][0] = 0 #dp[j][k]=j使って重要度kを達成する幅の最小値
num = 0
for x in range(N):
    A,B = map(int, input().split())
    for j in range(x,-1,-1):
        for k in range(num+1):
            dp[j+1][k+B] = min(dp[j][k]+A,dp[j+1][k+B])
    num += B

value = 0
for x in range(K+1):
    for y in range(5100):
        if (dp[x][y] <=W):
            value=max(value,y)
print(value)