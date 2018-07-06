N, D = map(int, input().split())

def count_pf(n,p):
  f = 0
  while n % p == 0:
    f += 1
    n //= p
  return n,f

D, p2 = count_pf(D,2)
D, p3 = count_pf(D,3)
D, p5 = count_pf(D,5)

if D != 1:
  print(0)
  exit()

import numpy as np
dp = np.zeros((p2+1, p3+1, p5+1), dtype = 'f8')
dp[p2,p3,p5] = 1

"""
1: 0 0 0
2: 1 0 0
3: 0 1 0
4: 2 0 0
5: 0 0 1
6: 1 1 0
"""

for i in range(N):
  for (n2,n3,n5), cnt in np.ndenumerate(dp):
    dp[max(n2-1,0), n3, n5] += cnt
    dp[n2, max(n3-1,0), n5] += cnt
    dp[max(n2-2,0), n3, n5] += cnt
    dp[n2, n3, max(n5-1,0)] += cnt
    dp[max(n2-1,0), max(n3-1,0), n5] += cnt

  dp /= 6.0

print(dp[0,0,0])