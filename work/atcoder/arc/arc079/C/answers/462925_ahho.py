N,M = map(int, input().split())

memo = [False]*N
result = False

for i in range(M):
  a,b = map(int, input().split())
  if a == 1:
    result |= memo[b]
    memo[b] = True
  elif b == N:
    result |= memo[a]
    memo[a] = True

print('POSSIBLE' if result else 'IMPOSSIBLE')