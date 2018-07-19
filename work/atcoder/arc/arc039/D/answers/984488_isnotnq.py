M = 10 ** 9 + 7

def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)

def combination(n, k):
    return factorial(n) // (factorial(k) * factorial(n - k))

N, K = map(int, input().split())
if N <= K:
    print(combination(N, K % N) % M)
else:
    print(combination(N + K - 1, K) % M)