#!/usr/bin/env python3

import collections

def color(r):
    for i, (p, q) in enumerate([
            (1, 399),
            (400, 799),
            (800, 1199),
            (1200, 1599),
            (1600, 1999),
            (2000, 2399),
            (2400, 2799),
            (2800, 3199),
            (3200, 4800)
    ]):
        if p <= r <= q:
            return i

input()
a = collections.Counter([color(int(x)) for x in input().split()])
m = len(a) - (1 if 8 in a and len(a) > 1 else 0)
print(m, m + a[8] - (1 if 8 in a and len(a) == 1 else 0))
