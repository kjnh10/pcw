import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline()

a, b = na()
s = ns().strip()
import re
if re.match("^[0-9]{" + str(a) + "}-[0-9]{" + str(b) + "}$", s):
    print("Yes")
else:
    print("No")
