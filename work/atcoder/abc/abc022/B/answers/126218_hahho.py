visited = set()
N = int(input())

cnt = 0
for i in range(N):
  n = int(input())
  if n in visited:
    cnt += 1
  else:
    visited.add(n)

print(cnt)