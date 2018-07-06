import sys
stdin = sys.stdin
def na(): return map(int, stdin.readline().split())
def ns(): return stdin.readline().strip()

a,b,c = na()
print(a*b*c%1000000007)