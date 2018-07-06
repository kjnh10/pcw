import sys
stdin = sys.stdin

n,q=map(int,stdin.readline().split())

imos = [0] * (n+2)
for i in range(q):
    l,r = map(int,stdin.readline().split())
    imos[l] ^= 1
    imos[r+1] ^= 1
for i in range(n+1):
    imos[i+1] ^= imos[i]

for i in range(1,n+1):
    sys.stdout.write(str(imos[i]))
print()
