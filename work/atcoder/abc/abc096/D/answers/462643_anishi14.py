# coding: utf-8
def eratosthenes(n):
    prime_table = [False,False,True]+[False if i%2!=0 else True for i in range(n-2)]
    i=3
    primes=[]
    while i*i<=n:
        if prime_table[i]:
            j=i*i
            while j<=n:
                prime_table[j]=False
                j+=i
        i+=2
    for i in range(len(prime_table)):
        if prime_table[i]:
            primes.append(i)
    return primes

a=eratosthenes(55555)    
n=int(input())
ans=[]
for i in range(len(a)):
    if a[i]%5==1:
        ans.append(a[i])
    if len(ans)==n:
        break
print(*ans)