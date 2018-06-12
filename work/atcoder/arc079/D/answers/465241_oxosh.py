# D
K = int(input())

N = 50

L = K // 50
R = K % 50

a_list = []

if R != 0:
    for i in range(50):
        if i >= 50 - R:
            a_list.append(str(99 - R + 1 + L))
        else:
            a_list.append(str(49 - R + L))
else:
    for i in range(50):
        a_list.append(str(49 + L))
        
print(len(a_list))
print(" ".join(a_list))