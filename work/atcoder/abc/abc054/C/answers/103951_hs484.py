N, M = map(int, input().split())

g = [ [False] * N for _ in range(N) ]
for _ in range(M):
  a, b = map(int, input().split())
  a -= 1
  b -= 1
  g[a][b] = True
  g[b][a] = True

vis = [False] * N
ans = 0
def f(v, d):
  global vis, ans
  if d == N:
    ans += 1
    return
  for nxt in range(N):
    if g[v][nxt] and not vis[nxt]:
      vis[nxt] = True
      f(nxt, d + 1)
      vis[nxt] = False

vis[0] = True
f(0, 1)
print(ans)