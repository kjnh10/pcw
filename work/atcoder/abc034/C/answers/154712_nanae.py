import sys
from fractions import gcd

sys.setrecursionlimit(10**6)

MOD = 10**9 + 7

def solve():
    W, H = map(int, input().split())

    ans = modcomb(W - 1 + H - 1, W - 1) % MOD

    print(ans)

def modcomb(n, r):
    if n - r < r:
        r = n - r

    if r == 0:
        return 1

    return (((n - r + 1) * modcomb(n, r - 1)) % MOD) * modinv(r, MOD) % MOD

def modinv(r, mod):
    return pow(r, mod - 2, mod)

def debug(x, table):
    for name, val in table.items():
        if x is val:
            print('DEBUG:{} -> {}'.format(name, val), file=sys.stderr)
            return None

if __name__ == '__main__':
    solve()