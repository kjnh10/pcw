h, w = map(int, input().split())
c = []
for i in range(10):
    c.append(list(map(int, input().split())))
for k in range(10):
    for i in range(10):
        for j in range(10):
            c[i][j] = min(c[i][j], c[i][k] + c[k][j])
ans = 0
for j in range(h):
    a = list(map(int, input().split()))
    for j in range(w):
        if a[j] != -1:
            ans += c[a[j]][1]
print(ans)
