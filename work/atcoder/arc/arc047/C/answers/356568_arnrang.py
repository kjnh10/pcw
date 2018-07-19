# coding: utf-8
# Here your code !
import numpy as np
n,L = [int(x) for x in input().split(' ')]
list = input()
sum = 1
re = 0
for i in list:
    if i == '+':
        sum += 1
        if sum > L:
            re +=1
            sum = 1
    else:
        sum -= 1
        
print(re)
    
