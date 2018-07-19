w,a,b = map(int,input().split())
d = abs(b-a)-w
if d >0:
    print(d)
else: 
    print(0)