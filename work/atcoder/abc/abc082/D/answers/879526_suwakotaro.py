from collections import Counter
a=input().strip()
x,y=[int(i) for i in input().split(" ")]

e1=[0]
e2=[0]
f=0
t=0
for i in a:
  if i=='F':
    f+=1
  elif i=='T':
    if f!=0:
      if t==0:
        e1.append(f)
      elif t==1:
        e2.append(f)
    t=(t+1)%2
    f=0

if t==0:
  e1.append(f)
elif t==1:
  e2.append(f)

s={0}
o=0
for i in e1:
  if a[0]=='F' and o==1:
    s=set([k+i for k in s])
  else:
    sp=set([k+i for k in s])
    sm=set([k-i for k in s])
    s=sp|sm
  o+=1
r={0}
for i in e2:
  rp=set([k+i for k in r])
  rm=set([k-i for k in r])
  r=rp|rm


if x in s and y in r:
  print('Yes')
else:
  print('No')