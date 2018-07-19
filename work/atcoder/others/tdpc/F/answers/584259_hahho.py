N,K = map(int,input().split())

from collections import deque
from itertools import repeat

MOD = 10**9+7
dp = deque(repeat(0,K+1),maxlen=K+1)
dp[1] = 1

s = 1
for _ in range(N-1):
  s += (dp[0]-dp[-1])%MOD
  dp.appendleft(s)

print((dp[0]-dp[-1])%MOD)