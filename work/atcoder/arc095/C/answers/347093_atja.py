n = int(input())
a = list(map(int, input().split()))
b = sorted(a)
i, j = b[n // 2 - 1], b[n // 2]
for x in a:
    if x <= i:
        print(j)
    else:
        print(i)
