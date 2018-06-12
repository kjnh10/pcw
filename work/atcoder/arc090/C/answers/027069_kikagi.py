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

A = []
for _ in range(2):
  A.append(reads())

result = max(sum(A[0][:i+1]) + sum(A[1][i:]) for i in range(N))
print(result)