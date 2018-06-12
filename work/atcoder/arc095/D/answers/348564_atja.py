n = int(input())
a = list(map(int, input().split()))
m = max(a)
best = m
y = -1
for x in a:
    if x == m: continue
    if abs(x - m / 2) < best:
        best = abs(x - m / 2)
        y = x
print(m, y)
