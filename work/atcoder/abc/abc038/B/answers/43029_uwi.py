import sys


stdin = sys.stdin

a,b=map(int, stdin.readline().split())
c,d=map(int, stdin.readline().split())
if a == c or a == d or b == c or b == d:
    print("YES")
else:
    print("NO")
