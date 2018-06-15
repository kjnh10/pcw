st=input().split()
N=int(st[0]);C=int(st[1])
s=[0 for i in range(N)];t=[0 for i in range(N)];c=[0 for i in range(N)]
MT=0
for i in range(N):
    st=input().split()
    s[i]=int(st[0])-1;t[i]=int(st[1])-1;c[i]=int(st[2])-1
for i in range(N):
    if t[i]>MT:
        MT=t[i]
CBC=[[0 for i in range(MT+1)] for i in range(C)]
for i in range(N):
    for j in range(s[i]-1,t[i]):
        CBC[c[i]][j]=1
MaxC=0
for i in range(MT+1):
    NowC=0
    for j in range(C):
        if CBC[j][i]==1:
            NowC+=1
    if NowC>MaxC:
        MaxC=NowC
print(MaxC)