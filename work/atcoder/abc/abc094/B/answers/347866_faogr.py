n,m,x=map(int,input().split())
a=[int(k) for k in input().split()]
b=sum([1 for aa in a if aa < x])
print(min(b,m-b))