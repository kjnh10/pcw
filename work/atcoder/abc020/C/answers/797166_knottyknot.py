H, W, T = map(int, input().split())
inf = 10**18


s = []
for h in range(H):
  s.append(input())


start = 0
goal = 0

edges = []


for h in range(H):
  for w in range(W):
    if s[h][w] == 'S':
      start = h*W+w
    elif s[h][w] == 'G':
      goal = h*W+w

    if h > 0:
      edges.append((W*h+w, W*(h-1)+w))
    if h < H-1:
      edges.append((W*h+w, W*(h+1)+w))
    if w > 0:
      edges.append((W*h+w, W*h+(w-1)))
    if w < W-1:
      edges.append((W*h+w, W*h+(w+1)))


def is_ok(x):
  d = [inf] * H*W
  d[start] = 0
  for _ in range(H*W):
    for u, v in edges:
      if s[v//W][v%W] == '#':
        w = x
      else:
        w = 1
      d[v] = min(d[v], d[u]+w)
      if s[u//W][u%W] == '#':
        w = x
      else:
        w = 1
      d[u] = min(d[u], d[v]+w)
  return d[goal] <= T

# start: ok, end: NG
def bisect(start, end):
  if end-start <= 1:
    return start
  mid = (start+end)//2
  if is_ok(mid):
    return bisect(mid, end)
  else:
    return bisect(start, mid)


print(bisect(0, inf))