from sys import exit, setrecursionlimit, stderr
from functools import reduce
from itertools import *
from collections import defaultdict
from bisect import bisect

def read():
  return int(input())

def reads():
  return [int(x) for x in input().split()]

N, M = reads()
cakes = []
for _ in range(N):
  cakes.append(reads())

signs = (-1, 1)

ans = 0
for s1, s2, s3 in product(*([signs]*3)):
  xs = [x1 * s1 + x2 * s2 + x3 * s3 for x1, x2, x3 in cakes]
  xs.sort()
  xs.reverse()
  ans = max(ans, sum(xs[:M]))
print(ans)
