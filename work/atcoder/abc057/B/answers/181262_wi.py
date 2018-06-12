import sys

stdin = sys.stdin


def na(): return map(int, stdin.readline().split())


def ns(): return stdin.readline().strip()


n,m=na()
abss = []
for i in range(n):
    abss.append(list(na()))
cds = []
for i in range(m):
    cds.append(list(na()))

for ab in abss:
    mind = 999999999
    argmin = -1
    import math
    for j in range(m):
        v = abs(cds[j][0]-ab[0])+abs(cds[j][1]-ab[1])
        if v < mind:
            mind = v
            argmin = j
    print(argmin+1)