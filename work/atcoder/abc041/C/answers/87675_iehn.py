import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time

sys.setrecursionlimit(10**7)

n = int(input())
a = list(map(int, input().split()))
b = [[a[i],i] for i in range(n)]

b.sort()
b.reverse()

for i,j in b:
    print(j+1)


