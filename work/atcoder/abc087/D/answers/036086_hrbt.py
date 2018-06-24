#!/usr/bin/env python3
import sys
sys.setrecursionlimit(200002)

def dfs(s):
    for t, d in G[s]:
        if x[t] is None:
            x[t] = x[s] + d
            if not dfs(t):
                return False
        else:
            if x[t] - x[s] != d:
                return False
    return True

N, M = map(int, input().split())
x = [None] * N
G = [[] for _ in range(N)]
for i in range(M):
    L, R, D = map(int, input().split())
    L -= 1
    R -= 1
    G[L].append([R, D])
    G[R].append([L, -D])
ans = True
for i in range(N):
    if x[i] is None:
        x[i] = 0
        if not dfs(i):
            ans = False
print(('No', 'Yes')[ans])
