#!/usr/bin/env python3
# -*- coding: utf-8 -*-

x = int(input())

k = (x // 11)
ans = k * 2
x -= k * 11
if x >= 6:
    x -= 6
    ans += 1
if x > 0:
    ans += 1
print(ans)
