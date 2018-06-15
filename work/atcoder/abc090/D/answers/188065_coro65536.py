# C

N, K = map(int, input().split())

if K == 0:
    print(N**2)
    quit()

ans = 0
for i in range(1, N - K + 1):
    b = K + i
    x = int((N - K) / b)
    M = min(N, K + x*b + i - 1)

    ans += i*x + M - (K + x*b) + 1

print(ans)