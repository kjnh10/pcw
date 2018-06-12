# -*- coding: utf-8 -*-

# x y 111000
# k
# 110111
x, y = map(int, input().split())
k = int(input())

if k <= y:
    print(k + x)
else:
    print(y + (x - (k - y)))