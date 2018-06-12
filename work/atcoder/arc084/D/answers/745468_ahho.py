from collections import deque

K = int(input())

Q = deque((1,))
inf = float('inf')
L = [inf]*K
L[1] = 1

while Q[0] != 0:
  n = Q.popleft()
  a = (n+1)%K
  if L[a] > L[n]+1:
    L[a] = L[n]+1
    Q.append(a)
  b = (n*10)%K
  if L[b] > L[n]:
    L[b] = L[n]
    Q.appendleft(b)

print(L[0])