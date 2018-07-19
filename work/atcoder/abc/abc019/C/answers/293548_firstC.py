import numpy as np

# get N
N = int(input())

# get INDATA
INDATA = np.array(list(map(int, input().split())))

for i in range(N):
    while True:
        if INDATA[i] % 2 == 1:
            break
        else:
            INDATA[i] /= 2

INDATA_U = np.unique(INDATA)

# output
print(INDATA_U.size)
