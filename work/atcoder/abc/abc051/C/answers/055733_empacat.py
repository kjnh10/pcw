sx, sy, tx, ty = [int(i) for i in input().split()]
dx = tx - sx
dy = ty - sy
print(''.join(("U" * dy, "R" * dx,
         "D" * dy, "L" * dx,
         "L", "U", "U" * dy, "R", "R" * dx, "D",
         "R", "D", "D" * dy, "L", "L" * dx, "U")))
