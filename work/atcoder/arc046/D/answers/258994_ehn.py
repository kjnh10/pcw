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
    n = I()
    a,b = LI()
    if n <= a:
        return 'Takahashi'
    if n <= b+1:
        return 'Aoki'
    if a == b and n % (a+1) == 0:
        return 'Aoki'
    if a >= b:
        return 'Takahashi'
    return 'Aoki'


print(main())
