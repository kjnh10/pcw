N = int(input())
A = list(map(int, input().split()))

B = []
ind = N - 1
for i in range(N - 1, -1, -2):
    B.append(A[i])

if N % 2 == 0:
    start = 0
else:
    start = 1

for i in range(start, N, 2):
    B.append(A[i])

print(" ".join(map(str, B)))
