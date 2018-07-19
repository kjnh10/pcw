#!/usr/bin/env python3
#fileencoding: utf-8

S = input()
l = [int(i) for i in input().strip().split(" ")]

for i,v in enumerate(S):
    if i in l:
        print('"', end='')
    print(v, end='')

if len(S) in l:
    print('"')
else:
    print()
