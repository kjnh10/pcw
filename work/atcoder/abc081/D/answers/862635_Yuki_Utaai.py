n=int(input())
a=[int(i) for i in input().split()]
count=0
ans=[[0 for i in range(2)] for j in range(2*n)]
aaa=0

a_max=max(a)
a_min=min(a)
if abs(a_max)>=abs(a_min):
    delta=a_max
else:
    delta=a_min
if delta>0:
    seifu=1
else:
    seifu=-1

for i in range(n):
    if delta==a[i]:
        aaa=i+1
        break




if seifu==1:

  for i in range(n-1):
    while a[i]>a[i+1]:
        if seifu==1:
            a[i+1]=a[i+1]+delta
            ans[count][0], ans[count][1]=aaa, i+2
        count=count+1
        a_max=max(a)
        delta=a_max
        for k in range(n):
            if delta==a[k]:
                aaa=k+1

else:
  for i in range(n-1):
    while a[n-2-i]>a[n-1-i]:
        if seifu==-1:
            a[n-2-i]=a[n-2-i]+delta
            ans[count][0], ans[count][1]=aaa, n-2-i+1
        count=count+1

        a_min=min(a)
        delta=a_min
        for k in range(n):
            if delta==a[k]:
                aaa=k+1


print(count)
for i in range(count):
    print(ans[i][0],ans[i][1])
