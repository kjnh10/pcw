N, T = map(int, input().split())
t = list(map(int, input().split()))

ans = 0
for i in range(1, N):
  if(t[i] - t[i-1] >= T): ans += T
  else: ans += (t[i] - t[i-1])


print(ans + T)

