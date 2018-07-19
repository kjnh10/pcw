N,D = map(int,input().split())

def divide_by_power(n,d):
  f = 0
  while n%d==0:
    f += 1
    n //= d
  return n,f

D,F2 = divide_by_power(D,2)
D,F3 = divide_by_power(D,3)
D,F5 = divide_by_power(D,5)

if D != 1:
  print(0)
  exit()

from collections import defaultdict

# 1 -> 0 0 0
# 2 -> 1 0 0
# 3 -> 0 1 0
# 4 -> 2 0 0
# 5 -> 0 0 1
# 6 -> 1 1 0

dp = defaultdict(int)
dp[(0,0,0)] = 1

delta = ((1,0,0),(0,1,0),(2,0,0),(0,0,1),(1,1,0))

for _ in range(N):
  ndp = dp.copy()
  for (i,j,k),n in dp.items():
    for di,dj,dk in delta:
      ndp[(min(i+di,F2),min(j+dj,F3),min(k+dk,F5))] += n
  dp = ndp

print(dp[(F2,F3,F5)]/(6**N))