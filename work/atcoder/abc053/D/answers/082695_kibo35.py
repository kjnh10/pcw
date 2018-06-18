import numpy as np
N = int(input())
A = list(map(int, input().split()))
M = len(np.unique(A))
print(M - (N - M) % 2)