import sys


stdin = sys.stdin

a,b,c = map(int,stdin.readline().split())
print(2*(a*b+b*c+c*a))
