N = int(input())

A = list(map(int,input().split()))

# max absolute value
_,mi = max((abs(v),i) for i,v in enumerate(A))
mi += 1

print(2*N-2)
for i in range(1,N+1):
  if i != mi:
    print(mi,i)

if A[mi-1] > 0:
  for i in range(1,N):
    print(i,i+1)
else:
  for i in reversed(range(1,N)):
    print(i+1,i)
