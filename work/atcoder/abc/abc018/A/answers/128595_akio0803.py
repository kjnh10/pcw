
T = [int(input()) for i in range(3)]

T = sorted(list(enumerate(T)), key=lambda x: x[1])[::-1]
T = sorted(list(enumerate(T)), key=lambda x: x[1][0])

for t in T:
    print(t[0] + 1)
