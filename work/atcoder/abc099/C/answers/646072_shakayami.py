def sinsu(M,k):
    L=0
    MM=M
    while(True):
        L+=MM%k
        MM=MM//k
        if MM==0:
            break
    return L
N=int(input())
ans=N
for i in range(N+1):
    a=i
    b=N-i
    tmp=sinsu(a,6)+sinsu(b,9)
    if ans>tmp:
        ans=tmp
print(ans)
