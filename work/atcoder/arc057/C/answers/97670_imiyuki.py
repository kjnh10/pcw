#!/usr/bin/env python3
l = 2*10**12
a, k = map(int,input().split())
if k == 0:
    i = l - a
else:
    i = 0
    while a < l:
        a += 1 + k*a
        i += 1
print(i)
