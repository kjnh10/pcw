n = int(input())
a = list(map(int, input().split()))
res = 0
while True:
    change = 0
    for i in range(n - 1):
        if a[i] == i + 1:
            a[i], a[i + 1] = a[i + 1], a[i]
            res += 1
            change = 1
    for i in range(n - 1, 1, -1):
        if a[i] == i + 1:
            a[i], a[i - 1] = a[i - 1], a[i]
            res += 1
            change = 1
    if change == 0:
        break

print(res)