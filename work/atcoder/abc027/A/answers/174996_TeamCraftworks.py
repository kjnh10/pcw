a,b,c = map(int,input().split())
if a == b and b == c:
    print(a)
elif a == b:
    print(c)
elif a == c:
    print(b)
elif b == c:
    print(a)
