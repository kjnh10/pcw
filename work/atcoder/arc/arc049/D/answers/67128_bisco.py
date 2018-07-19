#!/usr/bin/env python3
#fileencoding: utf-8

N = int(input())
L = [[int(j) for j in input().strip().split(" ")] for i in range(N)]

def norm(x,y,c,gx,gy,gc):
    nx = abs(x-gx) * c * gc / (c + gc)
    ny = abs(y-gy) * c * gc / (c + gc)
    return nx if nx > ny else ny

minimum = -1
for i in range(N):
    for j in range(i+1,N):
        tmp = norm(L[i][0],L[i][1],L[i][2],L[j][0],L[j][1],L[j][2])
        if tmp > minimum:
            minimum = tmp

print(minimum)
