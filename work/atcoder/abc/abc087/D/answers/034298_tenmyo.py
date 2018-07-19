import collections
from pprint import pprint as pp

N,M = tuple(map(int, input().split()))
LRD = collections.defaultdict(list)
Lset = set()
Rset = set()
for _ in range(M):
  l,r,d = map(int, input().split())
  l -= 1
  r -= 1
  LRD[l].append((r,d))
  Lset.add(l)
  Rset.add(r)

n = [ None for _ in range(N) ]

deq = collections.deque()

def func(l):
  lst = LRD.pop(l,[])
  for r,d in lst:
    if n[l] != None:
      d2 = n[l] + d
    else:
      n[l] = 0
      d2 = d
    if n[r] not in (d2, None):
      return True
    n[r] = d2
    deq.append(r)
  return False

def func2():
  lst = Lset-Rset
  for l in lst:
    n[l] = 0
    deq.append(l)
  while deq:
    l = deq.popleft()
    if l in LRD:
      if func(l):
        return True
  deq.extend(LRD.keys())
  while deq:
    l = deq.popleft()
    if l in LRD:
      if func(l):
        return True
  return False

if func2():
  print('No')
else:
  print('Yes')
