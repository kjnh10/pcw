# -*- coding: utf-8 -*-
from collections import deque

N = int(input())
R = [list(map(int, input().split(" "))) for _ in range(N)]
B = [list(map(int, input().split(" "))) for _ in range(N)]
R.sort(key=lambda x:(x[1],x[0]), reverse=True)
B.sort(key=lambda x:(x[0],x[1]))
R = deque(R)
B = deque(B)
f = [0]*N

pair = 0
for b in B:
    for i, r in enumerate(R):
        if r[0]<b[0] and r[1]<b[1] and f[i] == 0:
            pair += 1
            f[i] = 1
            break
    
print(pair)