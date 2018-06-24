# coding: utf-8
# Your code here!

import copy
import math
A,B = input().split(" ")
A = int(A)
B = int(B)
shot = 100 * (A-B) + 1900 * B
times = 2**B
print(shot*times)