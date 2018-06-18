#!/usr/bin/env python
# -*- coding: utf-8 -*-

_ = int(input())

d = dict()

sin = input()
for n in [int(s) for s in sin.strip().split()]:
    if n in d:
        d[n] += 1
    else:
        d[n] = 1
# print3d)
N = 0
for v in d.values():
    N += (v-1)
# print(N)

Nuniq = len(list(d.keys()))
ans = Nuniq - (0 if N%2==0 else 1)

print(ans)
