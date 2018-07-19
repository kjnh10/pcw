# -*- coding: utf-8 -*-

import sys
import os

H, W = map(int, input().split())

A = []
for i in range(H):
    A.append(input().strip())

print('#' * (W + 2))
for a in A:
    print('#{}#'.format(a))
print('#' * (W + 2))
