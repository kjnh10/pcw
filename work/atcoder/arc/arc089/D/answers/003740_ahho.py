N,K = map(int,input().split())

import numpy as np
blacks = np.zeros((2*K,2*K), dtype=int)

offset = 0

for _ in range(N):
  x,y,c = input().split()
  x,y = int(x),int(y)
  x %= 2*K
  y %= 2*K
  if c == 'B':
    blacks[x,y] += 1
  else:
    blacks[x,y] -= 1
    offset += 1

m = np.zeros((3*K,2*K),dtype=int)
m[:2*K,:] = blacks
m[2*K:,:] = blacks[:K,:]

np.cumsum(m,axis=0, out=m)

m = m[K:,:] - m[:2*K,:]

n = np.zeros((2*K,3*K),dtype=int)
n[:,:2*K] = m
n[:,2*K:] = m[:,:K]

np.cumsum(n,axis=1, out=n)
n = n[:,K:] - n[:,:2*K]

m = np.zeros((3*K,3*K),dtype=int)
m[:2*K,:2*K] = n
m[2*K:,:2*K] = n[:K,:]
m[:2*K,2*K:] = n[:,:K]
m[2*K:,2*K:] = n[:K,:K]

m = m[:2*K,:2*K] + m[K:,K:]
m = m.max()

print(m+offset)