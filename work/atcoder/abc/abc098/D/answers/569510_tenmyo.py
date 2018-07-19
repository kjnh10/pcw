from collections import defaultdict as dd
from collections import Counter
from pprint import pprint as pp

YN = {True: 'Yes', False: 'No'}
ri = lambda: int(input())
ria = lambda: list(map(int, input().split()))
rian = lambda n: [ria() for _ in range(n)]
rs = lambda: input()
rsa = lambda: input().split()
rsn = lambda n: [rs() for _ in range(n)]

N = ri()
A = ria()

ret = 0
l = 0
lr = 0

acc = 0
while l < len(A) and lr < len(A):
  if acc & A[lr] == 0:
    ret += 1
    acc |= A[lr]
    lr += 1
    if lr == len(A):
      for i in range(len(A) - l):
        ret += i
      break
  else:
    acc ^= A[l]
    l += 1
    if l != lr:
      ret += lr - l

print(ret)