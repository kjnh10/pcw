#!/usr/bin/env python
# -*- coding: utf-8 -*-

def local_input():
    from pcm.utils import set_stdin
    import sys
    if len(sys.argv) == 1:
        set_stdin(os.path.dirname(__file__) + '/test/' + 'sample-1.in')


import sys
import os
from sys import stdin, stdout
import time
import re
from pydoc import help
import string
import math
# import numpy as np  # codeforceでは使えない
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
ALPHABETS = [chr(i) for i in range(ord('a'), ord('z')+1)]  # can also use string module
def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def DP(N, M, first): return [[first] * M for n in range(N)]
def DP3(N, M, L, first): return [[[first] * L for n in range(M)] for _ in range(N)]


def solve():
    global T, N, g
    N = int(input())

    T = [[] for _ in range(N)]
    for n in range(N-1):
        # a, b = map(lambda x:int(x)-1, input().split())
        a, b = map(lambda x:int(x)-1, stdin.readline().rstrip().split())
        T[a].append(b)
        T[b].append(a)

    # print(T)

    g = -1
    for n, t in enumerate(T):
        if len(t) >= 3 and g==-1:
            g = n
        elif len(t) >= 3 and g!=-1:
            print("No")
            return

    if g == -1:
        print("Yes")
        print("1")
        res = []
        for n, t in enumerate(T):
            if len(t) == 1:
                res.append(n+1)
        print(*res)
        return

    print("Yes")
    print(len(T[g]))
    res = ""
    for n in T[g]:
        res += str(g+1)+" "+str(get_tip(n)+1)+"\n"
    stdout.write(res)

def get_tip(n):
    R = [0]*N
    R[g] = 1
    now = n
    while True:
        if len(T[now]) == 1:
            return now
        if R[T[now][0]] == 0:
            R[now] = 1
            now = T[now][0]
        elif R[T[now][1]] == 0:
            R[now] = 1
            now = T[now][1]

if __name__ == "__main__":
    try:
        local_input()
    except:
        pass
    solve()

