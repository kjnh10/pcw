import math

q = int(input())
a = []
for i in range(q):
    a.append(list(map(int, input().split())))
for i in range(q):
    b = max(2 * int(math.sqrt(a[i][0] * a[i][1])) - 3, 0)
    while True:
        status = True
        if b % 2 == 0:
            if (b // 2 + (a[i][0] <= b // 2)) * (b // 2 + 2 - (a[i][1] >= b//2 + 2)) < a[i][0] * a[i][1] and (b // 2 + 1 + (a[i][0] <= b // 2 + 1)) * (b // 2 + 1 - (a[i][1] >= b // 2 + 1)) < a[i][0] * a[i][1]:
                b = b + 1
            else:
                break
        else:
            if ((b - 1) // 2 + (a[i][0] <= (b - 1) // 2)) * ((b + 5) // 2 - (a[i][1] >= (b + 5) // 2)) < a[i][0] * a[i][1] and ((b + 1) // 2 + (a[i][0] <= (b + 1) // 2)) * ((b + 3) // 2 - (a[i][1] >= (b + 3) // 2)) < a[i][0] * a[i][1] and ((b + 3) // 2 + (a[i][0] <= (b + 3) // 2)) * ((b + 1) // 2 - (a[i][1] >= (b + 1) // 2)) < a[i][0] * a[i][1]:
                b = b + 1
            else:
                break
    print(b - 1)