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
s = [0 if c == "o" else 1 for c in input()]

ans = [0] * N

for a, b in product([0, 1], [0, 1]):
  ans[0:2] = [a, b]
  for i in range(2, N):
    ans[i] = (ans[i-2] + ans[i-1] + s[i-1]) % 2
  b1 = (ans[N-2] + ans[N-1] + ans[0] + s[N-1]) % 2
  b2 = (ans[N-1] + ans[0] + ans[1] + s[0]) % 2
  if b1 == 0 and b2 == 0:
    print("".join("SW"[ans[i]] for i in range(N)))
    exit()


print(-1)
