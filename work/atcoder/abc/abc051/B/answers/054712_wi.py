# coding=utf-8

import sys
stdin = sys.stdin
def na(): return map(int, stdin.readline().split())
def ns(): return stdin.readline().strip()

def main():
    ct = 0
    k,s = na()
    for i in range(0, k+1):
        for j in range(0, k+1):
            if 0 <= s-(i+j) <= k:
                ct += 1
    print(ct)
    pass


if __name__ == '__main__':
    main()