A,K=[int(i) for i in input().strip().split()]
e=2*10**12
d=0
if K>0:
    while True:
        if(A>=e):
            break
        A=A+1+A*K
        d+=1
else:
    d=e-A
print(d)

