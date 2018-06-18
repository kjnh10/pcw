#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys
import re
import math
import collections
import itertools
import functools

DEBUG = True
DEBUG = False

def dbg(*args):
    if DEBUG:
        print("DBG: ", file=sys.stderr, end="")
        print(*args, file=sys.stderr)



def main():
    N, M = map(int, input().split())

    mid1 = set()
    mid2 = set()
    for _ in range(M):
        a, b = map(int, input().split())
        if a == 1:
            mid1.add(b)
        elif b == N:
            mid2.add(a)

    result = bool(mid1 & mid2)
    print("POSSIBLE" if result else "IMPOSSIBLE")

if __name__ == "__main__": main()
