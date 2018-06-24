import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time

sys.setrecursionlimit(10**7)
inf = 10**20
mod = 10**9 + 7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()


def main():
    n,m = LI()
    x = LI()
    y = LI()

    a = 0
    t = 0
    for i in range(1,n):
        sa = x[i] - x[i-1]
        t += sa * i
        t %= mod
        a += t
        a %= mod

    b = 0
    t = 0
    for i in range(1,m):
        sa = y[i] - y[i-1]
        t += sa * i
        t %= mod
        b += t
        b %= mod


    return a * b % mod



print(main())