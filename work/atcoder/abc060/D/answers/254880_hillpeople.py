n,m=map(int,input().split())
a=[tuple(map(int,input().split())) for _ in range(n)]
d = {}
def f(i,j):
    if i==n:
        return 0
    if (i,j) not in d:
        d[i,j]=f(i+1,j)
        w,v=a[i]
        if j+w<=m:
            d[i,j]=max(d[i,j],v+f(i+1,j+w))
    return d[i,j]
print(f(0,0))