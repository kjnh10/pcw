# D
import numpy as np
N = int(input())
A = np.array(list(map(int, input().split())))

# pop from left
popleft = [0]*(N+1)
A_LEFT = np.argsort(A[:(2*N)])
ind_left = 1
for i in range(N):
    while popleft[ind_left] > 0:
        ind_left += 1
    if A_LEFT[i] < N:
        popleft[ind_left] = A[A_LEFT[i]]
    else:
        popleft[max(ind_left, A_LEFT[i] - (N-1))] = A[A_LEFT[i]]
left_sum = np.cumsum(A)[(N-1):(2*N)] - np.cumsum(np.array(popleft))

# pop from right
popright = [0]*(N+1)
A_RIGHT = np.argsort(-A[::-1][:(2*N)])
ind_right = 1
for i in range(N):
    while popright[ind_right] > 0:
        ind_right += 1
    if A_RIGHT[i] < N:
        popright[ind_right] = A[3*N - 1 - A_RIGHT[i]]
    else:
        popright[max(ind_right, A_RIGHT[i] - (N-1))] = A[3*N - 1 - A_RIGHT[i]]
right_sum = np.cumsum(A[::-1])[(N-1):(2*N)] - np.cumsum(np.array(popright))

# print(popleft)
# print(popright)
res = (left_sum - right_sum[::-1]).max()
# extreme case
res1 = (np.sort(A[:2*N])[N:]).sum() - A[2*N:].sum()
res2 = A[:N].sum() - (np.sort(A[N:])[:N]).sum()
print(max(res, res1, res2))