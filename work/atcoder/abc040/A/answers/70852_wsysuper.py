def read():
    return map(int, input().split())

n, x = read()
print(min(x - 1, n - x))
