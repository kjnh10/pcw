#! /usr/bin/env python3
# -*- coding: utf-8 -*-

import sys
DEBUG = False

H, W = map(int, input().split())

Y        = ['#' * (W+2)] + ['#' + line.rstrip() + '#' for line in sys.stdin] + ['#' * (W+2)]
X        = ['#' * (W+2)] + ['#' + '.' * W + '#'] * H + ['#' * (W+2)]
Ypredict = ['#' * (W+2)] + ['#' + '.' * W + '#'] * H + ['#' * (W+2)]

for i in range(1,H+1):
    for j in range(1, W+1):
        if Y[i][j-1:j+2] == '###' \
           and Y[i+1][j-1:j+2] == '###'\
           and Y[i-1][j-1:j+2] == '###':
            X[i] = X[i][:j] + '#' + X[i][j+1:]

for i in range(1,H+1):
    for j in range(1, W+1):
        if X[i][j] == '#':
            Ypredict[i-1] = Ypredict[i-1][:max(0,j-1)] + '###' + Ypredict[i-1][j+2:]
            Ypredict[i]   = Ypredict[i][:max(0,j-1)]   + '###' + Ypredict[i][j+2:]
            Ypredict[i+1] = Ypredict[i+1][:max(0,j-1)] + '###' + Ypredict[i+1][j+2:]

if DEBUG:
    print('Y')
    for row in Y:
        print(row)
    print('---')
    print('X')
    for row in X:
        print(row)
    print('---')
    print('Ypredict')
    for row in Ypredict:
        print(row)

if Y == Ypredict:
    print('possible')
    for row in X[1:-1]:
        print(row[1:-1])
else:
    print('impossible')
