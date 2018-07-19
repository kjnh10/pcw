import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools

sys.setrecursionlimit(10**7)
inf = 10**3
eps = 1.0 / 10**10
mod = 10**9+7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()
def pf(s): return print(s, flush=True)


def main():
    n,k = LI()
    dp = collections.defaultdict(int)
    sm = collections.defaultdict(int)
    sm[1] = dp[0] = 1
    for i in range(1,n+2):
        if i != 1 and i != n:
            dp[i] = (sm[i] - sm[max(i-k,0)] + mod) % mod
        sm[i+1] = (sm[i] + dp[i]) % mod

    return dp[n+1]


print(main())

