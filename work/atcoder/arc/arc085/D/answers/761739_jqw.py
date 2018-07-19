#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from math import *
import random

def readln():
    return list(map(int,(input().split(" "))))

n,z,w = readln()
a = readln()
f = [0 for i in range(n)]
min_f = [0 for i in range(n)]
max_min_f = [0 for i in range(n)]

s = [a[n - i - 1] for i in range(n)]
s.append(w)

f[0] = abs(s[0] - s[1])
min_f[0] = f[0]
max_min_f[0] = f[0]
for i in range(1,n):
    f[i] = max(abs(s[0] - s[i + 1]), max_min_f[i-1])
    min_f[i] = min(f[i],min_f[i-1])
    max_min_f[i] = max(min_f[i], max_min_f[i-1])


print(f[n-1])


# F[i] 表示y手里是i，x的最优解
