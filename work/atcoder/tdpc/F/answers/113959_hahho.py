from collections import deque
MOD = 1000000007
N,K = map(int, input().split())

dp = [0]*K # dp[末尾で何駅連続で止まったか] = 通り数
dp[1] = 1
dp = deque(dp, K+1)
s = 1

for n in range(1,N):
  dp.appendleft(s)
  s = (2*s - dp.pop()) % MOD

print((s - dp[0])%MOD)
