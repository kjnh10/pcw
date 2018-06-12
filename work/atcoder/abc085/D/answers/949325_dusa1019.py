#!/usr/bin/env python3
# coding=utf-8

import sys
import math
import numpy as np
n, h = map(int, sys.stdin.readline().strip().split(" "))
a = []
b = []
for _ in range(n):
    _a, _b = map(int, sys.stdin.readline().strip().split(" "))
    a.append(_a)
    b.append(_b)
max_a = max(a)
cnt = 0
b = np.asarray(sorted(b))
b = b[b > max_a]
while h > 0 and len(b) > 0:
    cnt += 1
    h -= b[-1]
    b = b[:-1]
if h > 0:
    cnt += math.ceil(h / max_a)
print(cnt)
