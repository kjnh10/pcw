import sys

stdin = sys.stdin


def na(): return map(int, stdin.readline().split())


def ns(): return stdin.readline().strip()


a,b = na()
print((a+b)%24)