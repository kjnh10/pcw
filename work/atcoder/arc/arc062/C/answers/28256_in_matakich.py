n = int(input())
x, y = 0, 0
for i in range(n):
    a, b = map(int, input().split())
    lb, ub = 0, 10 ** 19
    while ub - lb > 1:
        md = (lb + ub) // 2
        if a * md >= x and b * md >= y:
            ub = md
        else:
            lb = md
    x, y = a * ub, b * ub
print(x + y)
