#!/usr/bin/env python

cnt = 0
hoge = [0]

n = int(input())
s = list(input())

for x in s:
    if x == 'I':
        cnt += 1
    else:
        cnt -= 1
    hoge.append(cnt)

print(max(hoge))