import numpy as np

maxW = int(input())
N, maxK = map(int, input().split())

Arr = np.zeros((maxK + 1, maxW + 1))
for _ in range(N):
    w, val = map(int, input().split())
    if w > maxW:
        continue
    Arr[1:, w:] = np.maximum(Arr[:maxK, :maxW + 1 - w] + val, Arr[1:, w:])
print(int(Arr[maxK, maxW]))