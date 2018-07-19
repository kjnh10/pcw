N,K = map(int,input().split())
MOD = 10**9+7

def ncr(n,r):
    r = min(r, n-r)
    ret = 1
    for i in range(r):
        ret *= (n - i)
    for i in range(r):
        ret //= (r - i)
    return ret

if N <= K:
    ans = ncr(N, K%N) % MOD
    print(ans)
else:
    ans = ncr(N + K%N - 1, K%N) % MOD
    print(ans)
