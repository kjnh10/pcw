#!/usr/bin/env python3

n = int(input())
a = list(map(int, input().split()))
assert len(a) == n

a.append(0)

def all_path(a):
    res = 0
    now = 0
    for p in a:
        res += abs(now - p)
        now = p
    return res

def remove(a, i):
    if i == 0:
        prev = 0
    else:
        prev = a[i - 1]
    post = a[i + 1]
    now = a[i]
    orig = abs(now - prev) + abs(now - post)
    skip = abs(prev - post)
    return orig - skip

ap = all_path(a)

for i in range(n):
    print(ap - remove(a, i))

