# B
N = int(input())

l0 = 2
l1 = 1

for _ in range(N - 1):
    l0, l1 = l1, l0 + l1

print(l1)