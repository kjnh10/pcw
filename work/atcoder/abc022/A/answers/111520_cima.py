n,s,t=map(int,input().split())
w=int(input());c=1 if s<=w<=t else 0
for _ in [0]*(n-1):
     w+=int(input())
     if s<=w<=t:c+=1
print(c)