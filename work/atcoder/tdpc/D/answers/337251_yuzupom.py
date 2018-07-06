N,D = map(int, input().split())
a,b,c = 0,0,0

while(D%2 == 0):
    D /= 2
    a += 1

while(D%3 == 0):
    D /= 3
    b += 1

while(D%5 == 0):
    D /= 5
    c += 1

# 無理なものは無理
if D != 1 or a > 2*N or b > N or c > N :
    print(0)
    exit()

#dp[n][i][j][k]: n回サイコロを振ったとき,積でDを割った数が2^i * 3^j * 5^kになる場合の数
dp = [ [ [ [ 0 for i in range(c+1) ] for j in range(b + 1)] for k in range(a+1)] for l in range(N+1)]

#初期条件の設定
dp[0][a][b][c] = 1

for n in range(N):
    for i in range(max(0,a-2*n), a+1):
        for j in range(max(0,b-n), b+1):
            for k in range(max(0,c-n), c+1):
                test = [0 for x in range(6)]
                tmp = dp[n][i][j][k]
                if tmp == 0:
                    continue
                if i == 0 and j == 0 and k == 0:
                    dp[n+1][0][0][0] = tmp * 6
                else:
                    i1 = max(i-1, 0)
                    i2 = max(i-2, 0)
                    j1 = max(j-1, 0)
                    k1 = max(k-1, 0)

                    dp[n+1][i][j][k] += tmp
                    dp[n+1][i1][j][k] += tmp
                    dp[n+1][i][j1][k] += tmp
                    dp[n+1][i2][j][k] += tmp
                    dp[n+1][i][j][k1] += tmp
                    dp[n+1][i1][j1][k] += tmp

d = dp[N][0][0][0]
print("%.9f" % (d/(6**N)))
