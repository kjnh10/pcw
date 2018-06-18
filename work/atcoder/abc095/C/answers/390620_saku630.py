a, b, c, x, y = map(int, input().split())
num = float("inf")
for i in range(max(x, y) + 1):
    num = min(num, a * max(0, (x - i)) + b * max(0, (y - i)) + 2 * c * i)
print(num)