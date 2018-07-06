#!/usr/bin/env python3
# -*- coding: utf-8 -*-

N = int(input())
As = list(map(int,input().split()))

dp = [0] * N
dp[1] = abs(As[0] - As[1])
for i in range(2, N):
    dp[i] = min(dp[i-1] + abs(As[i] - As[i-1]),
                dp[i-2] + abs(As[i] - As[i-2]))
print(dp[N-1])
