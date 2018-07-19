N, Ma, Mb = map(int, input().split())

G = []
for i in range(N):
 a, b, c = map(int, input().split())
 G.append( (a,b,c) )

M = 1 + min(sum([ a for a, b, c in G ]),
            sum([ b for a, b, c in G ]) )
INF = 1000000000
dp = [INF] * (M * M)
dp[0] = 0
for a, b, c in G:
  i = M - a - 1
  while i >= 0:
    j = M - b - 1
    while j >= 0:
      dp[(i+a)*M+(j+b)] = min(dp[(i+a)*M+(j+b)], dp[i*M+j] + c)
      j -= 1
    i -= 1

ans = INF
x = 1
while Ma * x < M and Mb * x < M:
  ans = min(ans, dp[Ma * x * M + Mb * x])
  x += 1
if ans >= INF:
  ans = -1
print(ans)
