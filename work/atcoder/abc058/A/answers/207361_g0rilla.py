import sys
import math

INF = 10**9+7

stdin = sys.stdin
def na(): return map(int, stdin.readline().split())
def ns(): return stdin.readline().strip()
def nsl(): return list(stdin.readline().strip())
def ni(): return int(stdin.readline())
def nil(): return list(map(int, stdin.readline().split()))

a, b, c = nil()

if(b-a == c-b):
    print("YES")
else:
    print("NO")
