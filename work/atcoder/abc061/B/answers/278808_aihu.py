N,M = [int(x) for x in input().split()]
a=[]
b=[]
for i in range(M):
    A,B=[int(x) for x in input().split()]
    a.append(A)
    b.append(B)

for i in range(N):
    print(a.count(i+1)+b.count(i+1))
