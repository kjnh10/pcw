N = int(input())

F = []
for _ in range(N):
    f = []
    for i in input().split():
        f.append(1 if i == '1' else 0)
    F.append(f)

P = []
for _ in range(N):
    p = []
    for i in input().split():
        p.append(int(i))
    P.append(p)

ans = -1000000000
for i in range(1, 1024):
    val = 0
    S = []
    for j in range(10):
        S.append(1 if i & 2 ** j else 0)
    for k in range(N):
        n = 0
        for l in range(10):
            n += S[l] * F[k][l]
        val += P[k][n]
    if val > ans:
        ans = val

print(ans)
