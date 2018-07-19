import sys

stdin = sys.stdin


def na(): return map(int, stdin.readline().split())


def ns(): return stdin.readline().strip()


n,m = map(int,stdin.readline().split())

deg = [0]*n
for i in range(m):
    x, y = map(int, stdin.readline().split())
    deg[x-1] += 1
    deg[y-1]  += 1
for i in range(n):
    print(deg[i])