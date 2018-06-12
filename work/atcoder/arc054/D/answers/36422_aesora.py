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

P = float(input())

if P < (1.5 / math.log(2)):
    t = P
else:
    t = 1.5 / math.log(2) - 1.5 * math.log2(1.5 / P / math.log(2))
print(t)
