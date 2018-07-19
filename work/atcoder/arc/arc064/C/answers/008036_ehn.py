import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time

sys.setrecursionlimit(10**7)
inf = 10**10
mod = 10**9 + 7


def main():
    n,x = list(map(int, input().split()))
    a = list(map(int, input().split()))
    r = 0
    for i in range(n-1):
        wa = a[i] + a[i+1]
        if wa <= x:
            continue
        sa = wa - x
        r += sa
        if sa <= a[i+1]:
            a[i+1] -= sa
        else:
            a[i+1] = 0
    return r


print(main())
