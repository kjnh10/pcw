N = int(input())
A = list(map(int, input().split()))

def maxAbsIndex(arr):
  return max(range(len(arr)), key=lambda x: abs(arr[x]))

def p(x, y):
  print(str(x+1) + " " + str(y+1))

# align sign
idx = maxAbsIndex(A)
print(2*N)

for i in range(N):
  if i != idx:
    p(idx, i)
    A[i] += A[idx]
p(idx, idx)
A[idx] += A[idx]

#
sign = A[0] >= 0
for i in range(N):
  idx = maxAbsIndex(A)
  if sign:
    p(idx, i)
    A[i] += A[idx]
  else:
    p(idx, N-i-1)
    A[N-i-1] += A[idx]