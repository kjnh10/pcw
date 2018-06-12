import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time

sys.setrecursionlimit(10**7)
inf = 10**10
mod = 10**9 + 7


def main():
    s = input()
    l = len(s)
    if s[0] == s[-1]:
        if l%2 == 0:
            return 'First'
        return 'Second'
    if l%2 == 1:
        return 'First'
    return 'Second'



print(main())
