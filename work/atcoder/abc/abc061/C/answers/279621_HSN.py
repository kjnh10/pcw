n, k = map(int, input().split())
a = []
for i in range(n):
    x, y = map(int, input().split())
    a.append((x, y))
a.sort()
for i in range(n):
    if k - a[i][1] <= 0:
        print(a[i][0])
        break
    k -= a[i][1]
