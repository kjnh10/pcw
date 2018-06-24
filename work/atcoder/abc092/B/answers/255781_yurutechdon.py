N = int(input())
D, X = [int(_) for _ in input().split()]
A = [int(input()) for _ in range(N)]

r = 0

for i in range(1, D + 1):
    for j in A:
        if i % j == 1 or j == 1:
            r += 1

print(r + X)

