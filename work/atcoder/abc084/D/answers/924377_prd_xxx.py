MAXN = 10**5+10
sieve = [0,0] + [1]*MAXN
m = 2
while m*m <= MAXN:
    if sieve[m]:
        for n in range(2*m,MAXN,m):
            sieve[n] = 0
    m += 1

ok = [0]*MAXN
cums = [0]
for n in range(MAXN):
    if sieve[n] and sieve[(n+1)//2]:
        ok[n] = 1
    cums.append(cums[-1] + ok[n])

Q = int(input())
for i in range(Q):
    l,r = map(int,input().split())
    print(cums[r+1] - cums[l])
