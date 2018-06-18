# -*- coding: utf-8 -*-

import sys
import os
import math


N = int(input())
s_list = []
for i in range(N):
    s_list.append(input().strip())

alphabets = 'abcdefghijklmnopqrstuvwxyz'

for c in alphabets:
    min_count = float('inf')
    for s in s_list:
        count = s.count(c)

        if count < min_count:
            min_count = count
    print(c * min_count, end='')
print()