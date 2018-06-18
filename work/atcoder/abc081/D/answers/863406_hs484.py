N=int(input())
A=list(map(int,input().split()))

k = 0
for i in range(N):
  if abs(A[i]) > abs(A[k]):
    k = i
ans = []
if A[k] > 0:
  for i in range(N):
    if i != k:
      A[i] += A[k]
      ans.append((k+1, i+1))
  for i in range(N-1):
    A[i+1] += A[i]
    ans.append((i+1, i+2))
else:
  for i in range(N):
    if i != k:
      A[i] += A[k]
      ans.append((k+1, i+1))
  for i in range(N-1)[::-1]:
    A[i] += A[i+1]
    ans.append((i+2, i+1))
print(len(ans))
for x, y in ans:
  print(str(x) + " " + str(y))
