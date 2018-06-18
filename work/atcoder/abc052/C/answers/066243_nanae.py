import sys
import math

N = int(input())
M = 10 ** 9 + 7

factor = {}

for n in range(2, N + 1):
    p = 2
    root_n = math.sqrt(n)

    while n > 1 and p <= root_n:
        if n % p == 0:
            if p not in factor:
                factor[p] = 0

            while n % p == 0:
                n //= p
                factor[p] += 1

        p += 1

    if n > 1:
        if n not in factor:
            factor[n] = 1
        else:
            factor[n] += 1

# print(factor)

ans = 1

for v in factor.values():
    ans *= (v + 1)

ans %= M

print(ans)