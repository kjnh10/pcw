Na,Nb = map(int, input().split())
A = list(map(int, input().split()))[::-1]
B = list(map(int, input().split()))[::-1]

if Na > Nb:
  Na,Nb = Nb,Na
  A,B = B,A

dp = [None]*(Na+1)
# at i, dp[j] = (x,y) where x: optimal play score of black

# initialize
dp[0] = (0, 0)
for j in range(Na):
  x,y = dp[j]
  dp[j+1] = (y+A[j], x)

for i in range(Nb):
  x, y = dp[0] = (dp[0][1] + B[i], dp[0][0])
  
  for j in range(Na):
    xb, yb = dp[j+1]
    if yb + B[i] > y + A[j]:
      x, y = dp[j+1] = (yb + B[i], xb)
    else:
      x, y = dp[j+1] = (y + A[j], x)

print(x)