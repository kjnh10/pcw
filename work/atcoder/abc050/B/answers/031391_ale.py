n=int(input())
t=[int(i) for i in input().split()]
m=int(input())
for i in range(m):
    tc=t[:]
    p,x=map(int,input().split())
    tc[p-1]=x
    print(sum(tc))
