def f(x, y):
    return y * (x // y + (1 if x % y else 0))
n = int(input())
x, y = 1, 1
for i in range(n):
    t, a = (int(_) for _ in input().split())
    nx = f(x, t)
    ny = max(nx // t * a, f(y, a))    
    nx = ny // a * t
    x, y = nx, ny
print(x + y)
