res = 0
for i in range(3):
    s, e = [int(_) for _ in input().split()]

    res += s * e / 10

print(int(res))