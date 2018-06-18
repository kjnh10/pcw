import numpy as np
n = int(input())
a_list = [int(a) for a in input().split()]

N = max(a_list)
a_list.remove(N)

min_distance = 10**10
for a in a_list:
    if np.abs(N/2-a) < min_distance:
        min_distance = np.abs(N/2-a)
        M = a

print("{} {}".format(N, M))

