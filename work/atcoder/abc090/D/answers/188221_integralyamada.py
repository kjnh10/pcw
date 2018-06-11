N, K = map(int, input().split())
m = 0
if K == 0:
    print(N**2)
    exit()

for b in range(K+1,N+1):
    m += (b-K)*(N//b)
    if N%b-K >= 0:
        m += N%b-K+1
print(m)
