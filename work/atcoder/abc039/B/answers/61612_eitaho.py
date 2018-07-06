N = int(input())
x = int(N ** 0.25) - 1
while x ** 4 < N:
    x += 1
print(x)
