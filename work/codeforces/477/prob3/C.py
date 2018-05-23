#!/usr/bin/env python
# -*- coding: utf-8 -*-

IN = 'sample-1.in'  # sample case for local test
def local_test():
    try:
        from pcm.utils import set_stdin
        import sys
        if len(sys.argv) == 1:
            set_stdin(os.path.dirname(__file__) + '/test/' + IN)
    except:
        pass


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
INF = 10**20
GOSA = 1.0 / 10**10
MOD = 10**9+7
def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def DP(N, M, first): return [[first] * M for n in range(N)]
def DP3(N, M, L, first): return [[[first] * L for n in range(M)] for _ in range(N)]


import math
from bisect import bisect_left, bisect_right, insort_left, insort_right
def solve():
    global n,m,cl,ce,v,L,E,Q,a,b,c,d
    n, m, cl, ce, v = map(int, input().split())

    L = list(map(int, input().split()))
    E = list(map(int, input().split()))
    Q = int(input())

    RES = []
    for q in range(Q):
        a,b,c,d = map(int, input().split())

        if a == c: # same floor
            RES.append(abs(b-d))
            continue

        res = float('inf')
        if cl >= 1:
            tmp = bisect_left(L, b)
            if 0 <= tmp <= (cl-1):
                res = min(calc(L[tmp], True),res)

            if 0 <= tmp-1 <= (cl-1):
                res = min(calc(L[tmp-1], True),res)

        if ce >= 1:
            tmp = bisect_left(E, b)
            if 0 <= tmp <= (ce-1):
                res = min(calc(E[tmp], False),res)

            if 0 <= tmp-1 <= (ce-1):
                res = min(calc(E[tmp-1], False),res)
        RES.append(res)
    [print(str(x)) for x in RES]


def calc(y, stair=True):
    if stair == True:
        return abs(b-y) + abs(d-y) + abs(a-c)
    else:
        return abs(b-y) + abs(d-y) + math.ceil(abs(a-c)/v)

if __name__ == "__main__":
    solve()

