n = int(input())
a = [[int(input()), i] for i in range(n)]
a.sort()

b = [None] * n
b[a[0][1]] = 0
t = 0
for i in range(1, n):
    if a[i - 1][0] < a[i][0]:
        t += 1
    b[a[i][1]] = t

for x in b:
    print(x)
