n,k = map(int,input().split())
l = [int(x) for x in input().split()]

ans = 1 
n-=k 
while n>0:
    n-=(k-1)
    ans+=1 
print(ans)