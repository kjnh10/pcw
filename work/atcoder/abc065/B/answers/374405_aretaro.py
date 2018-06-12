#coding: utf-8
import sys
N = int(input())
a = [int(input()) for _ in range(N)]
p = 1
for i in range(N):
    if p == 2:
        print(i)
        sys.exit()
    p = a[p-1]
print(-1)
