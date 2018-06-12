N,M = map(int,input().split())

from collections import defaultdict
E = [list() for _ in range(N)]

for _ in range(M):
  l,r,d = map(int,input().split())
  E[l-1].append((r-1,d))
  E[r-1].append((l-1,-d))

locations = [None]*N

for s in range(N):
  if locations[s] is None:
    locations[s] = 0
    stack = [s]

    while stack:
      v = stack.pop()
      p = locations[v]

      for u,d in E[v]:
        if locations[u] is None:
          locations[u] = p+d
          stack.append(u)
        elif locations[u] != p+d:
          print('No')
          exit()


print('Yes')
