import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time

sys.setrecursionlimit(10**7)
inf = 10**10
mod = 10**9 + 7

def f():
    n = int(input())
    a,b = 1,1
    t = 0
    for _ in range(n):
        l,r = list(map(int, input().split()))
        ll = l
        rr = r
        if ll < a:
            s = a - ll
            ss = (s // l)
            while ss * l + ll < a:
                ss += 1
            ll += l*ss
            rr += r*ss
        if rr < b:
            s = b - rr
            ss = (s // r)
            while ss * r + rr < b:
                ss += 1
            ll += l*ss
            rr += r*ss
        a = ll
        b = rr
        t = ll + rr
    return t

print(f())
