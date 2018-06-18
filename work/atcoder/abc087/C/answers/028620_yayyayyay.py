n=int(input())
A1=list(map(int,input().split(' ')))
A2=list(map(int,input().split(' ')))
L=0
i=0
while i < n:
    l=sum(A1[:i+1])+sum(A2[i:])
    if L < l:
        L=l
    i+=1
print(L)