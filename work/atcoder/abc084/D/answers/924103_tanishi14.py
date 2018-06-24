from itertools import accumulate
# Eratosthenes
def eratosthenes(n):
    prime_table = [False,False,True]+[False if i%2!=0 else True for i in range(n-2)]
    i=3
    while i*i<=n:
        if prime_table[i]:
            j=i*i
            while j<=n:
                prime_table[j]=False
                j+=i
        i+=2
    return prime_table

pt=eratosthenes(100000)
ok=[0 for i in range(100000)]
i=1
while i<100000:
    if pt[i] and pt[(i+1)//2]:
        ok[i]=1
    i+=2
ok=list(accumulate(ok))

q=int(input())
for i in range(q):
    l,r=map(int,input().split())
    print(ok[r]-ok[l-1])
    
