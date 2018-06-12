from sys import exit, setrecursionlimit, stderr
from functools import reduce
from itertools import *
from collections import defaultdict
from bisect import bisect

def read():
  return int(input())

def reads():
  return [int(x) for x in input().split()]

(N, C) = reads()

x, v = [], []
for _ in range(N):
  X, V = reads()
  x.append(X)
  v.append(V)

psumr = [0] * (N+1)
psuml = [0] * (N+1)

INF = 10**20

pmaxr = [0] * (N+1)
pmaxl = [0] * (N+1)

for i in range(N):
  psumr[i+1] = psumr[i] + v[i]
  pmaxr[i+1] = max(pmaxr[i], psumr[i+1] - x[i])

for i in range(N-1, -1, -1):
  psuml[i] = psuml[i+1] + v[i]
  pmaxl[i] = max(pmaxl[i+1], psuml[i] - (C - x[i]))

ans0 = max(pmaxr[N], pmaxl[0])
ans1 = max((psumr[i+1] - 2 * x[i] + pmaxl[i+1] for i in range(N)))
ans2 = max((psuml[i] - 2 * (C - x[i]) + pmaxr[i] for i in range(N)))
print(max(ans0, ans1, ans2))
