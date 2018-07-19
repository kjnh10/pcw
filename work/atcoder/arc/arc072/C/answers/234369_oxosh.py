# C
n = int(input())
A = list(map(int, input().split()))
res_1 = 0
res_2 = 0

# first < 0
som_1 = 0
for i in range(n):
    if i % 2 == 1:
        som_1 += A[i]
        if som_1 >= 0:
            res_1 += (som_1 + 1)
            som_1 = -1
    else:
        som_1 += A[i]
        if som_1 <= 0:
            res_1 += (-som_1 + 1)
            som_1 = 1
# first > 0
som_2 = 0
for i in range(n):
    if i % 2 == 0:
        som_2 += A[i]
        if som_2 >= 0:
            res_2 += (som_2 + 1)
            som_2 = -1
    else:
        som_2 += A[i]
        if som_2 <= 0:
            res_2 += (-som_2 + 1)
            som_2 = 1
print(min([res_1, res_2]))