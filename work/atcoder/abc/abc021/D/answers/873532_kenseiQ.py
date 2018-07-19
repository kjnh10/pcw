def d_multi_loop(N, K):
    MOD = 10**9 + 7
    # フェルマーの小定理による組合せの計算
    factorial = [1] * (N + K)  # (N+K-1)!を計算するため。0!も入れておく
    for k in range(1, N + K - 1):
        factorial[k + 1] = (factorial[k] * (k + 1)) % MOD

    # k!のmod 10**9+7における逆元を計算
    fact_inv = [1] * (N + K)
    fact_inv[N + K - 1] = pow(factorial[N + K - 1], MOD - 2, MOD)
    for k in range(N + K - 1, 0, -1):
        fact_inv[k - 1] = (fact_inv[k] * k) % MOD

    def nCr(n, r, M):
        if n < 0 or r < 0 or n < r:
            return 0
        else:
            return (factorial[n] * fact_inv[r] * fact_inv[n - r]) % M

    def nHr(n, r, M):
        return nCr(n - 1 + r, r, M)

    return nHr(N, K, MOD)
  
N = int(input())
K = int(input())
print(d_multi_loop(N, K))