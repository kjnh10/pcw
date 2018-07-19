N=int(input())
A=list(map(int,input().split()))
ans=0
i=0
while i<N:
  if A[i]==i+1:
    ans+=1
    i+=2
  else: i+=1
print(ans)