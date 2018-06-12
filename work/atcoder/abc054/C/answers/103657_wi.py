import sys

stdin = sys.stdin
def na(): return map(int, stdin.readline().split())
def ns(): return stdin.readline().strip()

n,m = na()
g = [[0]*n for _ in range(n)]
for i in range(m):
    x,y = na()
    g[x-1][y-1] += 1
    g[y-1][x-1] += 1

import itertools

ct = 0
for a in itertools.permutations(range(n)):
    if a[0] != 0: break
    plus = 1
    for i in range(n-1):
        plus = plus * g[a[i]][a[i+1]]
    ct += plus
print(ct)