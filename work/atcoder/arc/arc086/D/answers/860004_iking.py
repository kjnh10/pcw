#!/usr/bin/python
# -*- coding: utf-8 -*-
import sys
import math
import collections

N, = list(map(int, sys.stdin.readline().rstrip().split()))
As = list(map(int, sys.stdin.readline().rstrip().split()))

Amin = min(As)
Amax = max(As)

if abs(Amax) >= abs(Amin):
    index = [i for i, item in enumerate(As) if item == Amax][0]
    print(2 * N - 1)
    for i in range(len(As)):
        print(index + 1, i + 1)
        As[i] += Amax
    for i in range(1, len(As), 1):
        print(i, i + 1)
        As[i] += As[i - 1]
else:
    index = [i for i, item in enumerate(As) if item == Amin][0]
    print(2 * N - 1)
    for i in range(len(As)):
        print(index + 1, i + 1)
        As[i] += Amin
    for i in range(len(As) - 2, -1, -1):
        print(i + 2, i + 1)
        As[i] += As[i + 1]
# print(As)
exit(0)
