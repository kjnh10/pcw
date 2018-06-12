# -*- coding: utf-8 -*-
from itertools import accumulate
def inpl(): return tuple(map(int, input().split()))
N, K = inpl()
P = [[0 for _ in range(2*K)] for _ in range(K)]

for _ in range(N):
    x, y, c = input().split()
    x, y = int(x), int(y)
    if c=="W":
        y += K
    x, y = x%(2*K), y%(2*K)
    if x >= K:
        if y < K:
            x -= K
            y += K
        else:
            x -= K
            y -= K
    
    P[0][y] += 1
    if x == K-1:
        if y == K-1:
            pass
        elif y > K-1:
            P[0][y-K] -= 1
        elif y < K-1:
            P[0][-1] += 1
            P[0][y+K] -= 1
    else:
        if y == K-1:
            P[x+1][-1] += 1
            P[x+1][y] -= 2
        elif y == 2*K-1:
            P[x+1][y-K] += 2
            P[x+1][y] -= 1
            P[0][y-K] -= 1
        elif y > K-1:
            P[x+1][-1] += 1
            P[x+1][y-K] += 2
            P[x+1][y] -= 2
            P[0][y-K] -= 1
        elif y < K-1:
            P[0][-1] += 1
            P[x+1][y+K] += 2
            P[x+1][-1] -= 1
            P[0][y+K] -= 1
            P[x+1][y] -= 2

S1 = [list(accumulate(l)) for l in zip(*P)]
S2 = [max(list(accumulate(l[::-1]))) for l in zip(*S1)]

print(max(S2))