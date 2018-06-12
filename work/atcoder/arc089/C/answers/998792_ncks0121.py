n = int(input())

x, y, t = 0, 0, 0
for i in range(n):
  t2, x2, y2 = map(int, input().split())
  d = abs(x-x2) + abs(y-y2)
  dt = t2 - t
  if d > dt or (dt - d) % 2 == 1:
    print("No")
    exit(0)
  x, y, t = x2, y2, t2

print("Yes")