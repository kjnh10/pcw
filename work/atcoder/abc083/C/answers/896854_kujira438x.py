# -*- coding: utf-8 -*-
x, y = list(map(int,input().split()))

elem = x
ans = 0
while(elem <= y):
    elem *= 2
    ans += 1
print(ans)