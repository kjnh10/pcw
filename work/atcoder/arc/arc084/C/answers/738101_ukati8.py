n=int(input())
A=input().split()
B=input().split()
C=input().split()
for i in range(n):
    A[i]=int(A[i])
    B[i]=int(B[i])
    C[i]=int(C[i])
C.sort()
C=C[::-1]
B.sort()
B=B[::-1]
A.sort()
A=A[::-1]


Cres=[1 for i in range(n)]
Bres=[0 for i in range(n)]
Ares=[0 for i in range(n)]

k=-1
for i in range(n):
    currsize=B[i]
    while k+1<n and currsize<C[k+1]:
        k+=1
    Bres[i]=k+1

k=-1
su=0
for i in range(n):
    currsize=A[i]
    while k+1<n and currsize<B[k+1]:
        k+=1
        su+=Bres[k]
    Ares[i]=su

su=0
for i in range(n):
    su+=Ares[i]
print (su)

