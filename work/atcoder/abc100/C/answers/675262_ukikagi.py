from sys import exit, setrecursionlimit, stderr
from functools import reduce
from itertools import *
from collections import defaultdict
from bisect import bisect

def read():
  return int(input())

def reads():
  return [int(x) for x in input().split()]

N = read()
a = reads()

def p2(x):
  res = 0
  while x & 1 == 0:
    x = x >> 1
    res += 1
  return res

ans = sum(p2(x) for x in a)
print(ans)