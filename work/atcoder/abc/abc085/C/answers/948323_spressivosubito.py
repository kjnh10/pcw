N, Y = map(int, input().split())
for y in range(N+1):
  up = Y - 1000*N - 4000*y
  if up >= 0 and up % 9000 == 0:
    x = up // 9000
    z = N - x - y
    if z >= 0:
      print(x, y, z)
      exit()
print("-1 -1 -1")