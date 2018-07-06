#!/usr/bin/env python
# -*- coding: utf-8 -*-

def num_ones_in_digit(n, digit):
    cycle = digit * 10

    # 周期に含まれる部分の計算
    num_ones = int(n / cycle) * digit
    res = n % cycle

    # 余り部分の計算
    if res + 1 > digit:
        num_ones += min(digit, res + 1 - digit)

    return num_ones    


n = int(input())
digit = 1
num_ones = 0
while int(n / digit) != 0: # 桁ごとに数える
    num_ones += num_ones_in_digit(n, digit)
    digit *= 10
print(num_ones)