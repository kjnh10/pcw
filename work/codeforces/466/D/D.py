#!/usr/bin/env python
# -*- coding: utf-8 -*-

IN = 'sample-1.in'
try: # this script's input{{{
    from pcm.utils import set_stdin
    import sys
    import os
    if len(sys.argv) == 1:  # not called by pcm test
        set_stdin(os.path.dirname(__file__) + '/test/' + IN)
except:
    pass  # }}}

# standard library# {{{
import sys
import os
import time
import re
from pydoc import help
import string
import math
import numpy as np
from operator import itemgetter
from collections import Counter
from collections import deque
from collections import defaultdict as dd
import fractions
from heapq import heappop, heappush, heapify
import array
from bisect import bisect_left, bisect_right, insort_left, insort_right
from copy import deepcopy as dcopy
import itertools
sys.setrecursionlimit(10**7)
inf = 10**20
gosa = 1.0 / 10**10
mod = 10**9+7
def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def DP(N, M, first): return [[first] * M for n in range(N)]
def DP3(N, M, L, first): return [[[first] * L for n in range(M)] for _ in range(N)]
# }}}


def solve():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, list(input())))

    # print(A, B)

    LMIN = -10**9
    LMAX = 10**9
    RMIN = -10**9
    RMAX = 10**9
    for i in range(4, n):
        if b[i-1] == 0 and b[i-2] == 0 and b[i-3] == 0 and b[i-4] == 0:
            if b[i] == 1:
                LMIN = max(LMIN, max(a[i],a[i-1],a[i-2],a[i-3],a[i-4])+1)
            elif b[i] == 0:
                LMAX = min(LMAX, max(a[i],a[i-1],a[i-2],a[i-3],a[i-4]))
        elif b[i-1] == 1 and b[i-2] == 1 and b[i-3] == 1 and b[i-4] == 1:
            if b[i] == 1:
                RMIN = max(RMIN, min(a[i],a[i-1],a[i-2],a[i-3],a[i-4]))
            elif b[i] == 0:
                RMAX = min(RMAX, min(a[i],a[i-1],a[i-2],a[i-3],a[i-4])-1)
        else:
            pass

    # print(LMIN, LMAX, RMIN, RMAX)

    # l = (LMIN + LMAX)//2

    print(LMIN, RMAX)

if __name__ == "__main__":
    solve()


