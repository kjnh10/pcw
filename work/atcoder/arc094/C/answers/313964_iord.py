a,b,c=map(int,input().split())
ret=0
while a+2<=max([a,b,c]):
    a+=2
    ret+=1
while b+2<=max([a,b,c]):
    b+=2
    ret+=1
while c+2<=max([a,b,c]):
    c+=2
    ret+=1
cnt=0
cnt+=1 if a<max([a,b,c]) else 0
cnt+=1 if b<max([a,b,c]) else 0
cnt+=1 if c<max([a,b,c]) else 0
if cnt==0:
    print(ret)
elif cnt==1:
    print(ret+2)
elif cnt==2:
    print(ret+1)