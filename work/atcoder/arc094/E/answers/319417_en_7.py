#!/usr/bin/env python3

import sys, math, copy
# import fractions, itertools
# import numpy as np
# import scipy

HUGE = 2147483647
HUGEL = 9223372036854775807
ABC = "abcdefghijklmnopqrstuvwxyz"

def main():
    n = int(input())
    an = []
    bn = []
    for i in range(n):
        a, b = map(int, input().split())
        an.append(a)
        bn.append(b)
    su = sum(an)
    assert sum(bn) == su

    if an == bn:
        return 0

    mi_b_smaller = HUGE
    for i in range(n):
        if an[i] > bn[i]:
            mi_b_smaller = min(mi_b_smaller, bn[i])

    return su - mi_b_smaller

print(main())

