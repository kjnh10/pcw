N,T=map(int,input().split())
ans=N*T
pa=-T
for _ in range(N):
  a = int(input())
  if pa + T > a:
    ans -= pa+T-a
  pa = a
print(ans)