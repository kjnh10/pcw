# -*- coding: utf-8 -*-
import heapq
import math
import sys
import bisect

N = int(input())
ABC = []
for i in range(3):
    tmp = input()
    t = [int(a) for a in tmp.split()]
    ABC.append(sorted(t))
ABC = ABC[::-1]
cumulative = [[i for i in range(N+1)][::-1]
               if j == 0 else [0 for i in range(N+1)]
              for j in range(3)]
for i in range(1, 3):
    for j, a in enumerate(ABC[i]):
        k = bisect.bisect_right(ABC[i-1], a)
        cumulative[i][j] = cumulative[i-1][k]
    for j, _ in enumerate(ABC[i]):
        cumulative[i][N-j-1] = cumulative[i][N-j-1] + cumulative[i][N-j]

print(cumulative[2][0])
