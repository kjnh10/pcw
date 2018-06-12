import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time

sys.setrecursionlimit(10**7)
inf = 10**20
mod = 10**9 + 7

def LI(): return list(map(int, input().split()))
def II(): return int(input())
def LS(): return input().split()
def S(): return input()


def main():
    n = II()
    s = [c == 'o' for c in S()]
    for k in ['SS','SW','WS','WW']:
        r = k
        for i in range(1,n-1):
            t = r[-1]
            t2 = r[-2]
            if (t == 'S' and t2 == 'S' and s[i]) or (
                t == 'S' and t2 == 'W' and not s[i]) or (
                t == 'W' and t2 == 'S' and not s[i]) or (
                t == 'W' and t2 == 'W' and s[i]):
                r += 'S'
            else:
                r += 'W'
        if ((((r[-1] == 'S' and s[-1]) or (r[-1] == 'W' and not s[-1]))  and  r[-2] == r[0]) or (
            ((r[-1] == 'W' and s[-1]) or (r[-1] == 'S' and not s[-1]))  and r[-2] != r[0])) and (
            (((r[0] == 'S' and s[0]) or (r[0] == 'W' and not s[0]))  and  r[-1] == r[1]) or (
            ((r[0] == 'W' and s[0]) or (r[0] == 'S' and not s[0]))  and r[-1] != r[1])):
            return r
    return -1

print(main())
