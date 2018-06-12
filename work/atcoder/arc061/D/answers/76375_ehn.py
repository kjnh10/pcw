import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time

sys.setrecursionlimit(10**7)
inf = 10**10


def f():
    h,w,n = list(map(int, input().split()))
    t = collections.defaultdict(int)
    for _ in range(n):
        a,b = list(map(int, input().split()))
        for i in range(3):
            if a+i < 3 or a+i > h:
                continue
            ai = (a+i) * inf
            for j in range(3):
                if b+j < 3 or b+j > w:
                    continue
                t[ai+b+j] += 1
    r = [0] * 10
    for v  in t.values():
        r[v] += 1
    r[0] = (h-2)*(w-2) - len(t)
    return "\n".join(map(str,r))

print(f())
