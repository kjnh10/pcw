import math,sys

#sys.setrecursionlimit(10**7)

n = int(input())
a = list(map(int, input().split()))
ra = [10**11]*n
ra[0] = 0

for i in range(n-1):
    rai = ra[i] + abs(a[i]-a[i+1])
    if rai < ra[i+1]:
        ra[i+1] = rai
    if i == n-2:
        continue
    rai = ra[i] + abs(a[i]-a[i+2])
    if rai < ra[i+2]:
        ra[i+2] = rai
print(ra[-1])




