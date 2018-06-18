n=int(input())
x=[int(a) for a in input().split()]
sx = sorted(x)
a=sx[n//2-1]
b=sx[n//2]
for c in x:
    if c <=a:
        print(b)
    else:
        print(a)