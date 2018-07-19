#!/usr/bin/env python3

input()
a = sorted([int(x) for x in input().split()])
print(max(a) - min(a))
