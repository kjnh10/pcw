N, M = map(int, input().split())
x_y_z = []
max_total = 0
for i in range(N):
    x_y_z.append(list(map(int, input().split())))
for i, j, k in [[1, 1, 1], [1, 1, -1], [1, -1, 1], [-1, 1, 1], [1, -1, -1], [-1, 1, -1], [-1, -1, 1], [-1, -1, -1]]:
    total_of_xyz = []
    total = 0
    for x, y, z in x_y_z:
        total_of_xyz.append(i * x + j * y + k * z)
    total_of_xyz.sort(reverse=True)
    for i in range(M):
        total += total_of_xyz[i]
    if max_total < total:
        max_total = total
print(max_total)