s=0
for _ in [0]*3:
    a,b=map(int,input().split())
    s+=a*b/10
print(int(s))