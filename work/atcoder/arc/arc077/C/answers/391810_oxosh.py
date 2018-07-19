# C
n = int(input())
a_list = list(input().split())

res_list = []
for i in range(n-1, -1, -2):
    res_list.append(a_list[i])
if n % 2 == 0:
    for i in range(0, n, 2):
        res_list.append(a_list[i])
else:
    for i in range(1, n, 2):
        res_list.append(a_list[i])
        
print(" ".join(res_list))