N = int(input())

S = 0
for n in range(1, 10):
    S += sum(list(range(1, 10))) * n

r = S - N

result = []
for x in range(1, 10):
    for y in range(1, 10):
        if x * y == r:
           print("{} x {}".format(x, y))