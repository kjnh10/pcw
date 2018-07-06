import math

N = int(input())
A = list(map(int, input().split()))
count = sum = 0
for i in range(N):
    if A[i] != 0:
        sum += A[i]
        count += 1

print(math.ceil(sum / count))
