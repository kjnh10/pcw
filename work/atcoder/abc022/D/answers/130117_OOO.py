import numpy as np
N = int(input())
def sd():
    vl = list()
    for i in range(N):
        x, y = [float(n) for n in input().split()]
        vl.append([x,y])
    V = np.array(vl)
    V -= np.mean(V, 0)
    return max(V[:, 0]**2+V[:, 1]**2)

print(np.sqrt(1/sd()*sd()))
