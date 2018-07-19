import math
xyz = input().split()
x = int(xyz[0])
y = int(xyz[1])
z = int(xyz[2])
ans = (x - z) / (y + z)
print(math.floor(ans))