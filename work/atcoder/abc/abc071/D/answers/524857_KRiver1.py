# -*- coding: utf-8 -*-
N = int(input())
S1 = input()
S2 = input()

MOD = 1000000007
i = 1
ans = 3
tp = 0
if S1[0] != S2[0]:
    i = 2
    ans = 6
    tp = 1
while i < N:
    if S1[i] == S2[i]:
        ans = (ans * [2, 1][tp]) % MOD
        i += 1
        tp = 0
    else:
        ans = (ans * [2, 3][tp]) % MOD
        i += 2
        tp = 1

print(ans)
