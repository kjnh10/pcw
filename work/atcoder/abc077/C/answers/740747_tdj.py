import sys
import math

N = int(input())
A = list(map(int, input().split(' ')))
B = list(map(int, input().split(' ')))
C = list(map(int, input().split(' ')))

A.sort()
B.sort()
C.sort()

array1 = list()
count = 0
f = 0
for j in range(N):
    for i in range(f, N):
        if B[N-1-j] < C[N-1-i]:
            count += 1
            if i == N-1:
                f = N
        else:
            f = i
            break
    array1.append(count)
ans = 0
f = 0
count = 0
for i in range(N):
    for j in range(f, N):
        if B[i] > A[j]:
            count += 1
            if j == N-1:
                f = N
        else:
            f = j
            break
    ans += count * array1[N-1-i]
print(ans)
