N, M = [int(_) for _ in input().split()]

res = [0] * (M + 2)
ans = 0
for _ in range(N):
    l, r, s = [int(_) for _ in input().split()]
    res[l] = res[l] + s
    res[r+1] = res[r+1] - s
    ans += s

for i in range(M+1):
    res[i+1] = res[i] + res[i+1]

print(ans - min(res[1:-1]))