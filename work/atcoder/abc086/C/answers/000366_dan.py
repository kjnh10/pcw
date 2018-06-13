N = int(input())

T, X, Y = [0], [0], [0]
for _ in range(N):
    t, x, y = map(int, input().split())
    T.append(t)
    X.append(x)
    Y.append(y)

ans = True
for i in range(N):
    d = abs(X[i] - X[i + 1]) + abs(Y[i] - Y[i + 1])
    t = T[i + 1] - T[i]
    if d > t or d % 2 != t % 2:
        ans = False

if ans:
    print('Yes')
else:
    print('No')
