# coding: utf-8
# Here your code !
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
 
import numpy as np
import bisect

N , Z ,W = input().split()
N = int(N)
Z = int(Z)
W = int(W)
a = input().split()
a = [int(i) for i in reversed(a)]

if N == 1 : 
    print(np.abs(W - a[0]))
else : 
    rst = [ np.abs(W - a[0]) , np.abs(a[1] - a[0]) ]
    print(np.max(rst))