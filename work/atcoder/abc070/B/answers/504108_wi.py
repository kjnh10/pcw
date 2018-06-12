import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline()

a,b,c,d = na()
print(max(0,min(b,d)-max(a,c)))
