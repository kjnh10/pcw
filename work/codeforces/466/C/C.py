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
    n, k = map(int, input().split())
    S = input()
    L = list(set(list(map(ord,S))))
    L.sort()

    I = {}
    for i, l in enumerate(L):
        I[l] = i

    first = L[0]
    last = L[-1]

    res = ""
    if k > n:
        res += S
        res += chr(first)*(k-n)
        print(res)
        return
    else:
        for i in reversed(range(k)):
            if ord(S[i]) < last:
                remained = L[I[ord(S[i])] + 1]
                res += S[:i]
                res += chr(remained)
                res += chr(first) * (k-i-1)
                print(res)
                return


if __name__ == "__main__":
    solve()


