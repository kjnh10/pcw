N, A, B = map(int, input().split())
ans=0
for i in range(N):
  t = 0
  j = i+1
  while j != 0:
    t += j%10
    j //= 10
  if A <= t and t <= B:
    ans += i+1

print(ans)