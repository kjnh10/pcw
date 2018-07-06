ALPHABETS = 26

ORD_A = ord('a')

# fast io
import sys
S,K = sys.stdin.readlines()[:2]

S = [ord(c)-ORD_A for c in S]
while S[-1] < 0:
  S.pop()


N = len(S)
K = int(K)

dp = [None]*(N+1)
dp[N] = 0
indices = [N]*ALPHABETS
s = 1

import sys

old = 1

for i,c in enumerate(reversed(S)):
  dp[i] = s
  if s > K:
    break
  s = 2*s
  s -= dp[indices[c]]
  indices[c] = i


dp.pop()
dp.reverse()
dp.append(0)

indices = [[] for _ in range(ALPHABETS)]
for i,c in enumerate(S):
  indices[c].append(i)
for l in indices:
  l.append(N)

del S

from bisect import bisect_left
def find(k):

  s = []
  i = 0
  while k > 0:
    f = False
    for c,L in enumerate(indices):
      j = L[bisect_left(L, i)]
      t = dp[j]
      if t is None or t >= k:
        s.append(c)
        k -= 1
        i = j+1
        f = True
        break
      else:
        k -= t
    if not f:
      break
  if not s:
    return 'Eel'
  return ''.join(chr(c+ORD_A) for c in s)

print(find(K))