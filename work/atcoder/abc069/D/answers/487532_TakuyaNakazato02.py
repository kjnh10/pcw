import numpy as np
H, W = map(int, input().split())
N = int(input())
a = list(map(int, input().split()))

hw = []

for i, ai in enumerate(a):
    for j in range(ai):
        hw.append(i+1)
        
hw = np.asarray(hw)
HW = np.reshape(hw, (H, W))

for i in range(H):
#     print(*HW[i])
    if i % 2 == 1:
        print(*HW[i][::-1])
    else:
        print(*HW[i])