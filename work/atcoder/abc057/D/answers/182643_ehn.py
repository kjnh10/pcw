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


def nCb(n, b):
    if b > n - b:
        b = n - b
    r = 1
    for k in range(n, n-b, -1):
        r = r * k
    d = 1
    for k in range(1, b+1):
        d = d * k
    return r // d

def main():
    n,a,b = LI()
    v = sorted(LI(),reverse=True)
    if v[0] == v[a-1]:
        t = a-1
        for i in range(a,n):
            if v[0] != v[i]:
                break
            t = i
        t += 1
        r = 0
        for i in range(a,min(b,t)+1):
            r += nCb(t,i)
        return "{}\n{}".format(v[0], r)

    t = 0
    tu = 0
    va = v[a-1]
    for i in range(n):
        if v[i] > va:
            tu += 1
        elif v[i] == va:
            t += 1
        else:
            break
    r = nCb(t,a-tu)
    return "{}\n{}".format(sum(v[:a]) * 1.0 / a, r)



print(main())
