n, m = map(int, input().split())
x = map(int, input().split())
y = map(int, input().split())

tmp_x = 0
for i, xi in enumerate(x):
    tmp_x += (xi + 1) * (2 * i - (n - 1))
tmp_x = tmp_x % 1000000007

tmp_y = 0
for i, yi in enumerate(y):
    tmp_y += (yi + 1) * (2 * i - (m - 1))
tmp_y = tmp_y % 1000000007

print ((tmp_x * tmp_y) % 1000000007) 