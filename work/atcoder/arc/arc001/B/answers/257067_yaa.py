a, b = map(int, input().split())
b = abs(b - a)
c = 0
if b == 0:
    print(c)
else:
    while b >= 8:
        b = abs(b - 10)
        c += 1
    while b >= 3:
        b = abs(b - 5)
        c += 1
    print(c+b)
