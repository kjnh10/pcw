# -*- coding: utf-8 -*-

import sys
import os
import math


A = input().strip()
B = input().strip()



if len(A) == len(B):
    for i in range(len(A)):
        print(A[i], end='')
        print(B[i], end='')
else:
    for i in range(len(B)):
        print(A[i], end='')
        print(B[i], end='')
    print(A[-1], end='')

