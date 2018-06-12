import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools

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

def main():
    sa,sb = LS()
    r = -999
    a = int(sa)
    b = int(sb)
    for i in range(3):
        ia = int(sa[:i] + '9' + sa[i+1:])
        if ia - b > r:
            r = ia - b
    for i in range(3):
        t = '0'
        if i == 0:
            t = '1'
        ib = int(sb[:i] + t + sb[i+1:])
        if a - ib > r:
            r = a - ib


    return r


print(main())
