from sys import exit, setrecursionlimit
from functools import reduce
from itertools import *
from collections import defaultdict
from bisect import bisect

def read():
  return int(input())

def reads():
  return [int(x) for x in input().split()]

setrecursionlimit(1000000)

(N, x) = reads()
a = [0] + reads()

result = 0

for i in range(1, N+1):
  if a[i] + a[i-1] >= x:
    result += max(a[i] + a[i-1] - x, 0)
    a[i] = min(x - a[i-1], a[i])

print(result)
