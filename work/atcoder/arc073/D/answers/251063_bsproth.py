N, W = map(int, input().split())
w, v = [0] * N, [0] * N

for i in range(N):
    w[i], v[i] = map(int, input().split())

memo = {i:{} for i in range(N)}

def r(i, g):
    global memo
    if i == N:
        return 0
    elif g in memo[i]:
        return memo[i][g]
    elif g < w[i]:
        a = r(i + 1, g)
    else:
        a = max(r(i + 1, g - w[i]) + v[i], r(i + 1, g))
    
    memo[i][g] = a
    return a

print(r(0, W))
