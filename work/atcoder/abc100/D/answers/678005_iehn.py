import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools

sys.setrecursionlimit(10**7)
inf = 10**20
eps = 1.0 / 10**10
mod = 998244353
dd = [(0,-1),(1,0),(0,1),(-1,0)]
ddn = [(0,-1),(1,-1),(1,0),(1,1),(0,1),(-1,-1),(-1,0),(-1,1)]

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()
def pf(s): return print(s, flush=True)


def main():
    n,m = LI()
    a = [LI() for _ in range(n)]
    r = sum(sorted([c[0]+c[1]+c[2] for c in a], reverse=True)[:m])
    tr = sum(sorted([c[0]+c[1]-c[2] for c in a], reverse=True)[:m])
    if r < tr:
        r = tr
    tr = sum(sorted([c[0]-c[1]-c[2] for c in a], reverse=True)[:m])
    if r < tr:
        r = tr
    tr = sum(sorted([c[0]-c[1]+c[2] for c in a], reverse=True)[:m])
    if r < tr:
        r = tr
    tr = sum(sorted([-c[0]+c[1]-c[2] for c in a], reverse=True)[:m])
    if r < tr:
        r = tr
    tr = sum(sorted([-c[0]+c[1]+c[2] for c in a], reverse=True)[:m])
    if r < tr:
        r = tr
    tr = sum(sorted([-c[0]-c[1]-c[2] for c in a], reverse=True)[:m])
    if r < tr:
        r = tr
    tr = sum(sorted([-c[0]-c[1]+c[2] for c in a], reverse=True)[:m])
    if r < tr:
        r = tr
    return r


print(main())

