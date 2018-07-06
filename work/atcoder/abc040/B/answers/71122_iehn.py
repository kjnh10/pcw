import math,sys

#sys.setrecursionlimit(10**7)

n = int(input())

r = n-1
for i in range(2,n):
    if i*i > n:
        break
    ri = abs(n//i-i) + (n-n//i*i)
    if r > ri:
        r = ri
print(r)


