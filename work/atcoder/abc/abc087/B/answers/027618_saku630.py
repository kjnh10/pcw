import itertools
a = int(input())
b = int(input())
c = int(input())
x = int(input())
R = [i for i in range(60)]
num = 0
for i, j, k in itertools.product(R[:a + 1], R[: b + 1], R[: c + 1]):
    if 500 * i + 100 * j + 50 * k == x:
        num += 1

print(num)