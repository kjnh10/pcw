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

N = read()

(T, X, Y) = (0, 0, 0)

for i in range(N):
  (t, x, y) = reads()
  d = abs(X-x) + abs(Y-y)
  if d <= t - T and (t - T - d)%2 == 0:
    (T, X, Y) = (t, x, y)
    continue
  else:
    print("No")
    exit()

print("Yes")
