#!/usr/bin/env python
# -*- coding: utf-8 -*-

IN = 'sample-1.in'  # this script's input
try:# {{{
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
    global CR, VR, W, N
    N = int(input())
    X = list(map(int, input().split()))
    C = list(map(int, input().split()))
    V = list(map(int, input().split()))

    MAX = 0
    for n in range(1, N):
        W = sum(X[:n])
        for comb in itertools.combinations(range(N), N-n):
            CR = [C[_] for _ in comb]
            VR = [V[_] for _ in comb]
            MAX = max(dfs(0, 0, 0), MAX)
    print(MAX)


def dfs(c, v, i):  # c,vでi+1から始めた場合の最大値
    if i == len(CR)-1:
        return v+VR[i] if c + CR[i] <= W else v
    else:
        return max(
            dfs(c, v, i+1),
            dfs(c+CR[i], v+VR[i], i+1) if c + CR[i] <= W else 0
            )


if __name__ == "__main__":
    solve()


