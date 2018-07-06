n=int(input())
a=map(int,input().split())
a=reversed(sorted(zip(a, range(1,n+1))))
for x in a:
    print(x[1])
