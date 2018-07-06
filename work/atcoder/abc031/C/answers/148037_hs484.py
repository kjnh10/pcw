N=int(input())
A=list(map(int,input().split()))

def f(a,b):
  if a > b:
    a, b = (b, a)
  x = 0
  y = 0
  s = 0
  for i in range(a, b+1):
    if s == 0:
      x += A[i]
    else:
      y += A[i]
    s = 1 - s
  return x, y

ans = -999999999999
for i in range(N):
  xx = 0
  yy = -999999999999 
  for j in range(N):
    if i == j: continue
    x,y = f(i,j)
    if yy < y:
       xx, yy = (x, y)
  ans = max(ans, xx)
print(ans)