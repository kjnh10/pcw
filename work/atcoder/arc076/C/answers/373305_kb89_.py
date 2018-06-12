import math
N,M=map(int,input().split())
if abs(N-M)>1:
  print(0)
elif abs(N-M)==1:
  n=math.factorial(N)%(10**9+7)
  m=math.factorial(M)%(10**9+7)
  print((n*m)%(10**9+7))
else:
  n=math.factorial(N)%(10**9+7)
  m=math.factorial(M)%(10**9+7)
  print((2*n*m)%(10**9+7))