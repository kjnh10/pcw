
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
    H, W, D = map(int, input().split())

    MAP = {}
    for h in range(H):
        L = list(map(int, input().split()))
        for w in range(W):
            MAP[L[w]] = (h,w)


    A = [0] * (H*W)
    for i in range(D, H*W):
        a, b = MAP[i+1]
        c, d = MAP[i+1-D]
        A[i] = A[i-D] + abs(a-c) + abs(b-d)

    Q = int(input())

    for q in range(Q):
        l, r = map(int, input().split())
        print(A[r-1]-A[l-1])
        

if __name__ == "__main__":
    solve()


