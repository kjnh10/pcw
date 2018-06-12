N, M = map(int, input().split())

def fac(n, mod):
    a = 1
    for i in range(n, 0, -1):
        a = (a * i) % mod
    return a
    
def solve(N, M):
    mod = 10**9 + 7
    if N > M + 1 or M > N + 1:
        return 0
    if N == M:
        return (2 * fac(N, mod)**2) % mod
    else:
        return (fac(N, mod) * fac(M, mod)) % mod

print(solve(N, M))