N,M = map(int,input().split())

INF = 100000000

g = [ [INF] * N for _ in range(N) ]

for _ in range(M):
  a,b,c = map(int,input().split())
  a-=1
  b-=1
  g[a][b] = c
  g[b][a] = c

t = [ [INF] * N for _ in range(N) ]
for i in range(N):
  for j in range(N):
    t[i][j] = g[i][j]

for k in range(N):
  for i in range(N):
    for j in range(N):
      t[i][j] = min(t[i][j], t[i][k] + t[k][j])

ans = 0
for i in range(N):
  for j in range(i):
    if g[i][j] != INF:
      if t[i][j] != g[i][j]:
        ans += 1
print(ans)