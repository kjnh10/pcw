N = int(input())

MAXN = 66666
sieve = [0,0] + [1]*MAXN
p = 2
while p*p <= MAXN:
    if sieve[p]:
        for q in range(2*p,MAXN+1,p):
            sieve[q] = 0
    p += 1

ans = []
for n in range(11,MAXN,10):
    if sieve[n]:
        ans.append(n)
        if len(ans) == N: break
print(*ans)
