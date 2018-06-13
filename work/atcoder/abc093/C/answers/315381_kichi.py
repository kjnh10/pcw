# -*- coding: utf-8 -*-
"""
C - Same Integers
https://beta.atcoder.jp/contests/abc093/tasks/arc094_a

"""
import sys
from sys import stdin
input = stdin.readline


def solve(numbers):
    ans = 0
    while numbers[0] != numbers[1] or numbers[0] != numbers[2]:
        numbers.sort()
        if numbers[0] + 2 <= numbers[2]:
            numbers[0] += 2
            ans += 1
        else:
            numbers[0] += 1
            numbers[1] += 1
            ans += 1
    return ans


def main(args):
    numbers = [int(x) for x in input().split()]
    ans = solve(numbers)
    print(ans)


if __name__ == '__main__':
    main(sys.argv[1:])
    
