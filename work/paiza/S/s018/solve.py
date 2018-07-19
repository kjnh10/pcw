#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys  # {{{
import os
import time
import re
from pydoc import help
import string
import math
from operator import itemgetter
from collections import Counter
from collections import deque
from collections import defaultdict as dd
import fractions
from heapq import heappop, heappush, heapify
import array
from bisect import bisect_left, bisect_right, insort_left, insort_right
from copy import deepcopy as dcopy
import itertools# }}}
import numpy as np

# pre-defined{{{
sys.setrecursionlimit(10**7)
INF = 10**20
GOSA = 1.0 / 10**10
MOD = 10**9+7
ALPHABETS = [chr(i) for i in range(ord('a'), ord('z')+1)]  # can also use string module
def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def DP(N, M, first): return [[first] * M for n in range(N)]
def DP3(N, M, L, first): return [[[first] * L for n in range(M)] for _ in range(N)]# }}}

# input
N, M, L = map(int, input().split())

def local_input():
    from pcm.utils import set_stdin
    import sys
    if len(sys.argv) == 1:
        set_stdin(os.path.dirname(__file__) + '/test/' + 'sample-1.in')

def solve():
    T = []
    for n in range(N):
        T.append([1 if x == 'S' else 0 for x in list(input())])

    origT = dcopy(T)

    r = 0
    D = []
    for k in range(1, 200):
        T, s = calc(T)
        print(np.array(T))
        if k == L:
            # こうでない循環も存在する。
            print(s)
            return

        D.append(s)
        if (np.array(T) == np.array(origT)).all():  # 何らかの周期性が存在する。
            r = k

    if r != 0:
        print(D[(L-1)%r])
    else:
        print(0)


def calc(T):
    res = [[0] * M for _ in range(N)]
    s = 0
    for n in range(N):
        for m in range(M):
            for i in [-1,0,1]:
                for j in [-1,0,1]:
                    res[n][m] += T[(n+i)%N][(m+j)%M]
            res[n][m] %= 2
            s += res[n][m]
    return res, s

if __name__ == "__main__":# {{{
    try:
        local_input()
    except:
        pass
    solve()
# vim: set foldmethod=marker:}}}
