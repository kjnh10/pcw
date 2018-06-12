from sys import exit, setrecursionlimit
from functools import reduce
from itertools import *
from collections import defaultdict
from bisect import bisect

def read():
  return int(input())

def reads():
  return [int(x) for x in input().split()]

(A, B, C, X, Y) = reads()

ans = 0

if A + B >= 2 * C:
  Z = min(X, Y)
  X, Y = X - Z, Y - Z
  ans += C * 2 * Z
  ans += min(A, 2 * C) * X
  ans += min(B, 2 * C) * Y
else:
  ans = A * X + B * Y

print(ans)
