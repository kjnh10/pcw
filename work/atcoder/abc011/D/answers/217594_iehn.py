import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy

sys.setrecursionlimit(10**7)
inf = 10**20
mod = 10**9 + 7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()

nm = {}
def nCb(n, b):
    if b > n - b:
        b = n - b
    key = (n,b)
    if key in nm:
        return nm[key]
    r = 1
    for k in range(n, n-b, -1):
        r = r * k
    d = 1
    for k in range(1, b+1):
        d = d * k
    nm[key] = r // d
    return nm[key]

def main():
    n,d = LI()
    x,y = LI()
    x,y = abs(x), abs(y)
    if x/d != x//d or y/d != y//d:
        return 0.0
    a,b = x//d, y//d

    r = 0
    at = 0
    for i in range(n+1):
        an = i
        bn = n-i
        t = nCb(n,i)
        at += t
        if a > an or b > bn or (an-a) % 2 == 1 or (bn-b) % 2 == 1:
            continue
        at = nCb(an, an - (an-a)//2)
        bt = nCb(bn, bn - (bn-b)//2)
        r += at * bt * t

    return r / 4**n

print(main())
