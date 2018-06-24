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
S = input()
cnt = {'E': [0, S.count('E')],
       'W': [0, S.count('W')]}

ret = N
for c in S:
  cnt[c][1] -= 1
  ret = min(ret, cnt['W'][0] + cnt['E'][1])
  cnt[c][0] += 1
print(ret)