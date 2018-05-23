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
    global N, A
    N = int(input())
    A = list(map(int, input().split()))

    C1 = [];C2 = []
    c1 = 0;c2 = 0
    for a in A:
        if a == 1:
            c1 += 1
        else:
            c2 += 1
        C1.append(c1)
        C2.append(c2)

    MAX = C1[-1] # first condition
    for i in range(N):
        if A[i] == 1:
            pass
        else:
            flag1 = True
            flag2 = True
            count = 0
            for j in range(i, N):
                if flag1:
                    count += 1
                    MAX = max(MAX, C1[i-1] + count + (C2[-1]-C2[j]))
                    if j == N-1:
                        continue
                    if A[j+1] == 1:
                        flag1 = False
                elif flag2:
                    count += 1
                    MAX = max(MAX, C1[i-1] + count + (C2[-1]-C2[j]))
                    if j == N-1:
                        continue
                    if A[j+1] == 2:
                        flag2 = False
                elif A[j] == 1:
                    count += 1
                    MAX = max(MAX, C1[i-1] + count + (C2[-1]-C2[j]))
                else:
                    pass
    print(MAX)


if __name__ == "__main__":
    solve()


