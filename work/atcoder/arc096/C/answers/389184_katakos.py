a, b, c, x, y = list(map(int, input().split()))
if a + b <= 2 * c:
    print(a * x + b * y)
else:
    if x < y:
        print(min(c * 2 * x + b * (y - x), c * 2 * y))
    else:
        print(min(c * 2 * y + a * (x - y), c * 2 * x))
