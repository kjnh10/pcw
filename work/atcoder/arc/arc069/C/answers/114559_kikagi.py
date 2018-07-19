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

(N, M) = reads()

result = 0

k = min(N, M // 2)
(N, M) = (N - k, M - 2 * k)
result += k

k = M // 4
result += k

print(result)
