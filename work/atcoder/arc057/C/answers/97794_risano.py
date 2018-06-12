A, K = [int(x) for x in input().split()]
X = 2 * (10 ** 12)

if K == 0:
    print(max(X - A, 0))
else:
    for T in range(10000):
        if A >= X:
            print(T)
            break
        A += 1 + K * A;
