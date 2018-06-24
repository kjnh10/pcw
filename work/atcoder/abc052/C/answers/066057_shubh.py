def SieveOfEratosthenes(n):
    prime = [True for i in range(n + 1)]
    p = 2
    while (p * p <= n):

        if (prime[p] == True):

            for i in range(p * 2, n + 1, p):
                prime[i] = False
        p += 1
    lis = []
    for i in range(2,n+1):
        if prime[i]:
            lis.append(i)
    return lis

n = int(input())

lis1 = []

l = SieveOfEratosthenes(n)

for i in l:
    m = n
    z = i
    exp = 0
    while(m>=z):
        exp += m//z
        z*=i
    lis1.append(exp)

mul = 1
for i in lis1:
    mul *= (i+1)

print(mul%(10**9+7))

