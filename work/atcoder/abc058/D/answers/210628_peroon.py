# -*- coding: utf-8 -*-

import sys
import os
import math


n, m = list(map(int, input().split()))
X = list(map(int, input().split()))
Y = list(map(int, input().split()))

def sum_len(A):
    all_sum = 0
    previous_sum = 0
    for i in range(1, len(A)):
        now_sum = previous_sum + i * (A[i] - A[i-1])
        all_sum += now_sum
        previous_sum = now_sum
    return all_sum

a = 10**9 + 7
xl = sum_len(X)
yl = sum_len(Y)
#print(xl)
#print(yl)
print(xl * yl % a)