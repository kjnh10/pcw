# -*- coding: utf-8 -*-
import sys

n, y = list(map(int,input().split()))
for i in range(n+1):
    for j in range(n-i+1):
        k = n-i-j
        if(10000*i+5000*j+1000*k==y):
            print(str(i)+' '+str(j)+' '+str(k))
            sys.exit()
print('-1 -1 -1')