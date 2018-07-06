a,b=sorted(map(int,input().split()))
for _ in [0]*int(input()):
    c=int(input())
    if c<a:print(a-c)
    elif c>b:print(-1)
    else:print(0)