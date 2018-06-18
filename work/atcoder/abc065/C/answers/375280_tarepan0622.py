n, m = map(int, input().split())
M = 10**9 + 7

def fact(n):
    result = 1
    for i in range(2, n + 1):
        result *= i
        if result >= M:
            result %= M
    return result


def fact2(a, b):
    return (fact(a) * fact(b)) %M


if n == m:
    print(((fact(n)**2)*2) % M)
elif abs(n - m) == 1:
    print(fact2(n, m))
else:
    print(0)
