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

n = read()
a = reads()

result = 10**16

sig = (1, -1)

count = 0
psum = 0
for i in range(n):
  psum += a[i]
  if psum * sig[i%2] <= 0:
    count += 1 - psum * sig[i%2]
    psum = sig[i%2]

result = count

count = 0
psum = 0
for i in range(n):
  psum += a[i]
  if psum * sig[(i+1)%2] <= 0:
    count += 1 - psum * sig[(i+1)%2]
    psum = sig[(i+1)%2]

result = min(result, count)

print(result)
