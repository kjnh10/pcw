# -*- coding: utf-8 -*-
"""
Created on Sat Jun 18 20:59:53 2016

@author: dotha
"""


N = int(input())
a = list(map(int, input().split(' ')))
cost = [0]*N
cost[1] = abs(a[1]-a[0])
for i in range(2,N):
    cost[i] = min(abs(a[i]-a[i-1])+cost[i-1], abs(a[i] - a[i-2])+cost[i-2])
print(cost[N-1])