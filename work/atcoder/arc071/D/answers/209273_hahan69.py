n,m = list(map(int,input().split(" ")))

x = list(map(int,input().split(" ")))
y = list(map(int,input().split(" ")))

def how(i):
    j = i
    l = [j-1 for i in range(i-1)]
    j = i-3
    for k in range(1,len(l)):
        l[k] = l[k-1]+j
        j -= 2
    return(l)

xh = how(n)
yh = how(m)

xd = [x[i+1]-x[i] for i in range(n-1)]
yd = [y[i+1]-y[i] for i in range(m-1)]

xs = sum([xd[i]*xh[i] for i in range(n-1)])
ys = sum([yd[i]*yh[i] for i in range(m-1)])

print((xs*ys)%(10**9+7))