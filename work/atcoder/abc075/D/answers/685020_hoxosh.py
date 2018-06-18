# D
import numpy as np

N, K = map(int, input().split())
x_list = []
y_list = []

for _ in range(N):
    x, y = map(int, input().split())
    x_list.append(x)
    y_list.append(y)

x_list_np = np.array(x_list)
x_args = np.argsort(x_list_np)
x_sorted = np.sort(x_list_np)

res = (max(x_list) - min(x_list)) * (max(y_list) - min(y_list))

for i1 in range(N):
    for i2 in range(i1+K-1, N):
        x_ = x_sorted[i2] - x_sorted[i1]
        y_pick = np.sort(np.array(y_list)[x_args[i1:(i2+1)]])
        y_ = min([y_pick[i+K-1] - y_pick[i] for i in range(i2-i1-K+2)])
        res = min(res, x_*y_)
print(res)