import math

N = int(input())
X, Y = map(int, input().split())
for i in range(N - 1):
    T, A = map(int, input().split())
    if T >= X and A >= Y:
        X = T
        Y = A
    else:
        if X % T == 0:
            t = X // T
        else:
            t = X // T + 1
        if Y % A == 0:
            a = Y // A
        else:
            a = Y // A + 1
        X = T * max(a, t)
        Y = A * max(a, t)
print(X + Y)
