#!/usr/bin/env python3

from collections import deque

K = int(input())

d = [float('inf')] * K
d[1] = 1
q = deque([1])
while q:
    n = q.popleft()
    l, r = map(lambda x: (x) % K, [n * 10, n + 1])

    if d[l] > d[n]:
        d[l] = d[n]
        q.appendleft(l)

    if d[r] > d[n] + 1:
        d[r] = d[n] + 1
        q.append(r)

print(d[0])
