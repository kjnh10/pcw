import math,sys

#sys.setrecursionlimit(10**7)

n,x = list(map(int, input().split()))

print(min(x-1,n-x))


