import sys
sys.setrecursionlimit(sys.getrecursionlimit()*1000)
n = int(input())
g = [[] for _ in range(n+1)]
for _ in range(n-1):
    a, b = map(int, input().split())
    g[a].append(b)
    g[b].append(a)
a = []
def f(i, p):
    a.append(i)
    if i == n:
        return True
    for j in g[i]:
        if j != p:
            if f(j, i):
                return True
    a.pop()
f(1,0)
m = (len(a)+1) // 2
def h(i, j, p):
    if i == j:
        return 1
    return 1 + sum(h(k, j, i) for k in g[i] if k != p)
if h(1, a[m], 0) > h(n, a[m-1], 0):
    print("Fennec")
else:
    print("Snuke")
