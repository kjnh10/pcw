n=int(input())
k=int(input())
x=[int(x) for x in input().split()]
ans=0
from math import fabs
for i in x:
    ans+=min(fabs(i-k),fabs(i))
print(int(ans*2))