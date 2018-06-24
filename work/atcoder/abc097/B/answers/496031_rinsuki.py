x = int(input())

m = 1

for i in range(1, 32):
    for j in range(2, 10):
        p = pow(i, j)
        if p > x:
            break
        if p > m:
            m = p

print(m)