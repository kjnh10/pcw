#!/usr/bin/env python3
# coding=utf-8

import sys

a = int(sys.stdin.readline().strip())
b = int(sys.stdin.readline().strip())
c = int(sys.stdin.readline().strip())
x = int(sys.stdin.readline().strip())
ans = 0
for i in range(a+1):
    for j in range(b+1):
        for k in range(c+1):
            if i * 500 + j * 100 + k * 50 == x:
                ans += 1
print(ans)
