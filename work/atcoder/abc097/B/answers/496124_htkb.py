from math import sqrt
x = int(input())
for i in range(x, 0, -1):
    for j in range(int(sqrt(i)), 0, -1):
        for k in range(1, 10):
            if j**k == i:
                print(i)
                exit()