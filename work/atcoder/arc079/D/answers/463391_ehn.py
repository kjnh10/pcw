import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools

sys.setrecursionlimit(10**7)
inf = 10**20
gosa = 1.0 / 10**9
mod = 10**9 + 7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()


def main():
    K = I()
    N = 50
    a = [49] * 50
    k = K // 50
    kp = K % 50
    for i in range(N):
        t = k
        if i < kp:
            t += 1
        for j in range(N):
            if i == j:
                continue
            a[j] -= t
        a[i] += t * 50
    return '{}\n{}'.format(N, ' '.join(map(str,a)))



print(main())

