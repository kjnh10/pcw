# seishin.py
N, K = map(int, input().split())

# 素因数分解
F = {}
X = 2; Y = K
while X*X <= Y:
    if Y % X == 0:
        cnt = 0
        while Y % X == 0:
            Y //= X
            cnt += 1
        F[X] = cnt
    X += 1
if Y > 1:
    F[Y] = 1

*P, = sorted(F.items())
*E, = sorted(F.keys())
L = len(P)

from itertools import compress, combinations

MOD = 10**9 + 7

# GCD(i, K) = v となるi (1≦i≦N)の時のLCM和
# => GCD(j, K/v) = 1 となるi (1≦j≦N/v)の時のLCM和をv倍したもの
# => LCM(i, K/v)*v = i*(K/v)/GCD(i, K/v) * v = i*K/GCD(i, K/v) を計算
def calc(v, M):
    *e, = compress(E, M)
    N0 = N // v
    res = N0*(N0 + 1) // 2
    # K/v と約数を持たない数の和を包除原理から求める
    for l in range(1, len(e)+1):
        for P in combinations(e, l):
            u = 1
            for p in P: u *= p
            c = N0 // u
            if l % 2:
                res -= u*c*(c+1)//2
            else:
                res += u*c*(c+1)//2
        res %= MOD
    # i*K / GCD(i, K) の内のK倍
    res *= K
    return res % MOD

# 全ての約数列挙
def dfs(c, v, M):
    if c == L:
        return calc(v, M)
    x, k = P[c]
    r = 0
    for i in range(k+1):
        # K/v と x が約数を持つ場合、M[c] = 1
        M[c] = (i < k)
        r += dfs(c+1, v, M)
        v *= x
    return r % MOD
print(dfs(0, 1, [0]*L))
