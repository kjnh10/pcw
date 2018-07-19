N = int(input())
L = list(map(int,input().split()))
s = sum(L)
r = N*10**9
p = 0
for i in range(N-1):
  p += L[i]
  r = min(r,abs(2*p-s))
print(r)