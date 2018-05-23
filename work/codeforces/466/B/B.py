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
    k = int(input())
    A = int(input())
    B = int(input())

    if k==1:
        print((n-1)*A)
        return

    cost = 0
    x = n
    while True:
        if x == 1:
            print(cost)
            return

        r = x%k
        if r != 0:
            if x > k:
                cost += A*r
                x -= r
            else:
                cost += A*(r-1)
                x -= r-1
        else:
            tmp = x//k
            if A*(x-tmp) <= B:
                cost += A*(x-tmp)
                x -= (x-tmp)
            else:
                cost += B
                x //= k


if __name__ == "__main__":
    solve()


