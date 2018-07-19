n, h = map(int, input().split())
A = []; B = []
for i in range(n):
    a, b = map(int, input().split())
    A += a,; B += b,
a = max(A)

T = []
for i in range(n):
    if a < B[i]:
        T += B[i],
T.sort(reverse=True)
ans = 0
for t in T:
    h -= t; ans += 1
    if h <= 0:
        break
if h > 0:
    ans += (h + a - 1) // a
print(ans)

