# -*- coding: utf-8 -*-
"""
B - Small and Large Integers
https://beta.atcoder.jp/contests/abc093/tasks/abc093_b

"""
import sys
from sys import stdin
input = stdin.readline


def main(args):
    A, B, K = map(int, input().split())
    ans = set()

    for x in range(A, A+K):
        if x <= B:
            ans.add(x)
    for x in range(B-K+1, B+1):
        if x >= A:
            ans.add(x)

    res = list(ans)
    res.sort()
    print(*res, sep='\n')


if __name__ == '__main__':
    main(sys.argv[1:])
    
