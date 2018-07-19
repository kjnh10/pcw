a, b = list(map(int, input().split()))

if (a + b) % 2 == 1:
    print(int((a + b) / 2 + 1))
else:
    print(int((a + b) / 2))
