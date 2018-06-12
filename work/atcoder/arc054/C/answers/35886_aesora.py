# coding: utf-8

from __future__ import print_function
from __future__ import unicode_literals
from __future__ import division
from __future__ import absolute_import
import math
import string
import itertools
import fractions
import heapq
import collections
import re
import array
import bisect

def array2d(d1, d2, init = None):
    return [[init for _ in range(d1)] for _ in range(d2)]

L, X, Y, S, D = map(int, input().split(" "))

if S < D:
    dd = D - S
    ud = L - dd
else:
    ud = S - D
    dd = L - ud

ut = float(ud) / (Y - X) if Y > X else float("inf")
dt = float(dd) / (Y + X)
print(min(ut, dt))
