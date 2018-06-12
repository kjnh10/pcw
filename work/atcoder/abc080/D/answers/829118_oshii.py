N, C = map(int, input().split())

r = [[0 for i in range(C)] for j in range(100000)]
for _ in range(N):
    s, t, c = map(int, input().split())
    for i in range(s - 1, t):
        r[i][c - 1] = 1

ans = 0
for i in range(100000):
    val = sum(r[i])
    if val > ans:
        ans = val

print(ans)
