#!/usr/bin/python
# -*- coding: utf-8 -*-
import sys
import math

sets = [
    set([1,3,5,7,8,10,12]),
    set([4,6,9,11]),
    set([2])
]

def find_group(i):
    for index, group in enumerate(sets):
        if i in group:
            return index


H,W = map(int, sys.stdin.readline().rstrip().split())

targets = []

# H -> W
for h in (H//3, H//3 + 1):
    res = H-h
    targets.append([h*W, (W//2)*res, (W-W//2)*res])
    targets.append([h*W, (res//2)*W, (res-res//2)*W])
for w in (W//3, W//3 + 1):
    res = W-w
    targets.append([w*H, (H//2)*res, (H-H//2)*res])
    targets.append([w*H, (res//2)*H, (res-res//2)*H])

print(min([
    max(target) - min(target)
    for target in targets
]))

exit(0)
