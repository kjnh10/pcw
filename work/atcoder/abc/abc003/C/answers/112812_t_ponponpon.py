n,k=list(map(int,input().split(" ")))
r=list(map(int,input().split(" ")))
y=0.0
for i in range(n-k):
    mn=min(r)
    r.remove(mn)
for i in range(k):
    mn=min(r)
    r.remove(mn)
    y=(y+mn)/2

print(y)
