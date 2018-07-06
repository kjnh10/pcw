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
    k,n = LI()
    a = []
    for _ in range(n):
        t = LS()
        t[0] = [int(x)-1 for x in t[0]]
        t.append(len(t[1]))
        a.append(t)

    for ka in itertools.product(range(1,4), repeat=k):
        sd = [None] * k
        f = True
        for si, s, sl in a:
            l = sum(ka[i] for i in si)
            if sl != l:
                f = False
                break
            ssi = 0
            for i in si:
                if sd[i]:
                    if sd[i] != s[ssi:ssi+ka[i]]:
                        f = False
                        break
                else:
                    sd[i] = s[ssi:ssi+ka[i]]
                ssi += ka[i]

            if not f:
                break
        if not f:
            continue

        return '\n'.join(sd)

    return 0


print(main())
