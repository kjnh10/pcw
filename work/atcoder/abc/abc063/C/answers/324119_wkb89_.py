import sys
N=int(input())
S=[]
for i in range(N):
  S+=[int(input())] 
S.sort()

ans=0
for i in range(N):
  ans+=S[i]
if ans%10!=0:
  print(ans)
  sys.exit
else:
  for i in range(N):
    if S[i]%10!=0:
      print(ans-S[i])
      sys.exit()
  print(0)
