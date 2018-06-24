N=int(input())
a=list(map(int,input().split()))
b=[0]*9
for i in range(N):
  if a[i]<400:
    b[0]=1
  elif a[i]<800:
    b[1]=1
  elif a[i]<1200:
    b[2]=1
  elif a[i]<1600:
    b[3]=1
  elif a[i]<2000:
    b[4]=1
  elif a[i]<2400:
    b[5]=1
  elif a[i]<2800:
    b[6]=1
  elif a[i]<3200:
    b[7]=1
  else:
    b[8]+=1
if b[8]==N:#全員がつよい!
  print(1,min(N,8))
else:
  Min=0
  Max=0
  for i in range(8):
    Min+=b[i]
  print(Min,min(N,Min+b[8]))