MOD = 1000000007

D = int(input())
N = [int(s) for s in input()][::-1]

dp = [0]*D
dp[0] = 1  # D divides 0
total = sum(N) % D
result = 1 if total % D == 0 else 0

for n in N:
  total = (total - n) % D
  s = sum(dp[-(total+d)%D] for d in range(n))
  result = (result + s) % MOD

  if D > 10:
    cop = dp[-10:]
    s = sum(cop)
    for i in reversed(range(10, D)):
      t = s - dp[i] + dp[i-10]
      dp[i] = s % MOD
      s = t
    for i in reversed(range(10)):
      t = s - dp[i] + cop[i-10]
      dp[i] = s % MOD
      s = t
  else:
    cop = dp.copy()
    s = sum(dp[-(d+1)%D] for d in range(10)) % MOD
    for i in reversed(range(D)):
      dp[i] = s % MOD
      s = s - cop[i] + cop[(i-10)%D]

result = (result-1) % MOD # exclude N=0 case

print(result)