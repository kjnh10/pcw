v = 2025 - int(input())
for i in range(1, 10):
    for j in range(1, 10):
        if i * j == v:
            print("{} x {}".format(i, j))
        if i * j >= v:
            break