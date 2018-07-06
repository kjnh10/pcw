import sys

stdin = sys.stdin

n,q = map(int,stdin.readline().split())
a = [0]*n
for i in range(q):
    l,r,t = map(int,stdin.readline().split())
    for j in range(l,r+1):
        a[j-1] = t
for v in a:
    print(v)