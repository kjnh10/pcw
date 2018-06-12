# C
import numpy as np
N, M = map(int, input().split())

alpha = np.zeros(N+1)
omega = np.zeros(N+1)

for _ in range(M):
    a, b = map(int, input().split())
    if a == 1:
        alpha[b] = 1
    if b == N:
        omega[a] = 1
        
if (alpha*omega).sum() > 0:
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")