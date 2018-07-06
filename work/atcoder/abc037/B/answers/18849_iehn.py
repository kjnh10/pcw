import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys
mod = 1000000007

n,q = list(map(int, input().split()))
a = [0]*n

for _ in range(q):
    l,r,t = list(map(int, input().split()))
    for i in range(l-1,r):
        a[i] = t

for r in a:
    print(r)
