import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline()

s = ns().strip()
if s == s[::-1]:
    print("Yes")
else:
    print("No")