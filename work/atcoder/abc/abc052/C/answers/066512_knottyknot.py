N=int(input())
div=1000000007

primedict= {i:True for i in range(2,N+1)}

for i in range(2,N+1):
        if primedict[i]==True:
                j=2
                while i*j<=N:
                        primedict[i*j]=False
                        j+=1

primelist = [i for i in  range(2,N+1) if primedict[i]==True]

primecntdict={p:0 for p in primelist}

for n in range(2,N+1):
        for p in [p for p in primelist if p <= n]:
                while n%p==0:
                        n/=p
                        primecntdict[p]+=1

res=1
for p in primelist:
        res*=primecntdict[p]+1
        res%=div

print(res)
