import bisect
n=int(input())
a=[int(x) for x in input().split()]
y=sorted(a)
m=y[-1]
i = bisect.bisect_left(y,m/2.0)
if y[i]+y[i-1] >= m:
    print(str(m)+' '+str(y[i-1]))
else:
    print(str(m)+' '+str(y[i]))