import sys
sys.setrecursionlimit(200002)

n, m = map(int, input().split())
a = [[] for i in range(n)]
for i in range(m):
    l, r, d = map(int, input().split())
    l -= 1
    r -= 1
    a[l].append((r, d))
    a[r].append((l, -d))

bio = [None for i in range(n)]
def dfs(x):
    for y, d in a[x]:
        if bio[y] is None:
            bio[y] = bio[x] + d
            if not dfs(y):
                return False
        elif bio[y] != bio[x] + d:
            return False
    return True

for i in range(n):
    if bio[i] is None:
        bio[i] = 0
        if not dfs(i):
            print('No')
            exit(0)
print('Yes')
