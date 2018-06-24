c = [None for x in range(3)]
for x in range(3):
  c[x] = list(map(int, input().split()))

ok = True

for x in range(2):
  ok = ok and (c[x][0]-c[x+1][0] == c[x][1]-c[x+1][1] == c[x][2]-c[x+1][2])

for x in range(2):
  ok = ok and (c[0][x]-c[0][x+1] == c[1][x]-c[1][x+1] == c[2][x]-c[2][x+1])

print ("Yes" if ok else "No")
    