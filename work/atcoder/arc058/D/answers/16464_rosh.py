import functools

MOD = 1000000007

fact = [None] * 300000
fact[0] = 1
for i in range(1, 300000):
    fact[i] = (i * fact[i - 1]) % MOD

def comb(h, w):
    numer = fact[h - 1 + w - 1]
    denom = (fact[h - 1] * fact[w - 1]) % MOD
    # print('numer, denom =', numer, denom)

    return (numer * pow(denom, MOD - 2, MOD)) % MOD

H, W, A, B = map(int, input().split())
ans = 0
for h in range(H - A):
    x = comb(h + 1, B)
    y = comb(H - h, W - B)
    # print(x, y)
    ans += x * y
    ans %= MOD
print(ans)
