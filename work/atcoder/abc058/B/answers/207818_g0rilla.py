import sys
import math

INF = 10**9+7

stdin = sys.stdin
def na(): return map(int, stdin.readline().split())
def ns(): return stdin.readline().strip()
def nsl(): return list(stdin.readline().strip())
def ni(): return int(stdin.readline())
def nil(): return list(map(int, stdin.readline().split()))

o = ns()
e = ns()

ans = []
for i in range(len(e)):
    ans.append(o[i])
    ans.append(e[i])

if(len(o) - len(e) == 1):
    ans.append(o[-1])

print(''.join(ans))