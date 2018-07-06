L,H=map(int,input().split())
N=int(input())
for _ in range(N):
  A=int(input())
  if A < L:
    ans = L - A
  elif A > H:
    ans = -1
  else:
    ans = 0
  print(ans)
