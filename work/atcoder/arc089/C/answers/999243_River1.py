# -*- coding: utf-8 -*-
import heapq
import math
import sys

N = int(input())
t, x, y = 0, 0, 0
flag = True
for n in range(N):
    tmp = input()
    nt, nx, ny = [int(a) for a in tmp.split()]
    dt, dx, dy = nt - t, nx - x, ny - y
    d = abs(dx) + abs(dy)
    if d <= dt and d % 2 == dt % 2:
        continue
    else:
        flag = False
if flag:
    print('Yes')
else:
    print('No')
