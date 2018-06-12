N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
ans = 0

for i in range(N):#N番目で下に
  curr = 0
  for j in range(i+1):
    curr += A[j]
  for j in range(i,N):
    curr += B[j]
  ans = max(ans,curr)
  
print(ans)