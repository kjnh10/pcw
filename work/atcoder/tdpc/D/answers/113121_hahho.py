N, D = map(int, input().split())

# count 2, 3 and 5 in D
p2 = 0
while D % 2 == 0:
  p2 += 1
  D //= 2
p3 = 0
while D % 3 == 0:
  p3 += 1
  D //= 3
p5 = 0
while D % 5 == 0:
  p5 += 1
  D //= 5

if D != 1:
  print(0)
  exit()

from collections import defaultdict
dp = defaultdict(int)
dp[(0,0,0)] = 1

"""
1: 0 0 0
2: 1 0 0
3: 0 1 0
4: 2 0 0
5: 0 0 1
6: 1 1 0
"""

for i in range(N):
  ndp = list(dp.items())
  for e,cnt in ndp:
    n2, n3, n5 = e
    dp[(min(n2+1,p2), n3, n5)] += cnt
    dp[(n2, min(n3+1,p3), n5)] += cnt
    dp[(min(n2+2,p2), n3, n5)] += cnt
    dp[(n2, n3, min(n5+1,p5))] += cnt
    dp[(min(n2+1,p2), min(n3+1,p3), n5)] += cnt

print(dp[(p2,p3,p5)]/(6**N))