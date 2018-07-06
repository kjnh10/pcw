import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools

sys.setrecursionlimit(10**7)
inf = 10**20
gosa = 1.0 / 10**10
mod = 10**9 + 7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()


def main():
    k = I()
    n = 2**k
    a = [I() for _ in range(n)]

    m = {}
    def f(x,y):
        t = y-x
        if t in m:
            return m[t]
        m[t] = 1 / (1 + 10**(t/400))
        return m[t]

    r = [1] * n
    for i in range(k):
        t = [0] * n
        kt = (n-1) - (2**(i+1)-1)
        i2 = 2**i
        for j in range(n):
            jt = (j&kt) + (j&i2^i2)
            for l in range(i2):
                u = jt+l
                t[j] += r[j] * r[u] * f(a[j], a[u])
        r = t

    return '\n'.join(map(lambda x: '{:0.10f}'.format(x), r))


print(main())

