a,b,c,x,y=map(int,input().split())
ret=10**10
for i in range(2*max(x,y)+1):
    aleft=max(x-(i//2),0)
    bleft=max(y-(i//2),0)
    ret=min(ret,c*i+aleft*a+bleft*b)
print(ret)