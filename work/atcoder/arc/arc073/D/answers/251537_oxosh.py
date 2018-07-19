# D
import numpy as np
N, W = map(int, input().split())
v_list_0 = []
v_list_1 = []
v_list_2 = []
v_list_3 = []

w0, v0 = map(int, input().split())
v_list_0.append(v0)

for i in range(1, N):
    w, v = map(int, input().split())
    if w == w0:
        v_list_0.append(v)
    elif w == w0+1:
        v_list_1.append(v)
    elif w == w0+2:
        v_list_2.append(v)
    else:
        v_list_3.append(v)

# best weight
vn0 = np.cumsum([0] + sorted(v_list_0, reverse=True))
vn1 = np.cumsum([0] + sorted(v_list_1, reverse=True))
vn2 = np.cumsum([0] + sorted(v_list_2, reverse=True))
vn3 = np.cumsum([0] + sorted(v_list_3, reverse=True))

# find best n0, n1, n2, n3
vmax = 0
n3_max = min(len(v_list_3), W//(w0+3))
for n3 in range(n3_max+1):
    n2_max = min(len(v_list_2), (W - (n3*(w0+3)))//(w0+2))
    for n2 in range(n2_max+1):
        n1_max = min(len(v_list_1), (W - (n3*(w0+3) + n2*(w0+2)))//(w0+1))
        for n1 in range(n1_max+1):
            n0_max = min(len(v_list_0), (W - (n3*(w0+3) + n2*(w0+2) + n1*(w0+1)))//(w0))
            vnow = vn3[n3] + vn2[n2] + vn1[n1] + vn0[n0_max]
            if vnow > vmax:
                vmax = vnow
print(vmax)