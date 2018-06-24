n=int(input())
d,x=list(map(int, input().split(" ")))
a=[]
ans=x
for i in range(0,n):
    a.append(int(input()))
for i in range(0,d):
    for j in a:
        if i%j==0:
            ans+=1
print(ans)