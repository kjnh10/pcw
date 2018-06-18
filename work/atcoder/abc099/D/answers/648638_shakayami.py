import itertools
N,C=map(int,input().split())
D=[[int(i) for i in input().split()] for i in range(C)]
c=[[int(i)-1 for i in input().split()] for i in range(N)]
X=[[] for i in range(3)]
for i in range(N):
    for j in range(N):
        X[(i+j)%3].append(c[i][j])
for i in range(3):
    X[i].sort()
Z=[[0 for i in range(C)] for j in range(3)]
for i in range(3):
    for j in X[i]:
        Z[i][j]+=1
#iwakan
I=[[0 for i in range(C)] for j in range(3)]
for i in range(3):
    for j in range(C):
        for k in range(C):
            I[i][j]+=Z[i][k]*D[k][j]
S=itertools.permutations(range(C),3)
ans=10**9
for sg in S:
    tmp=0
    for i in range(3):
        tmp+=I[i][sg[i]]
    if ans>tmp:
        ans=tmp
print(ans)
