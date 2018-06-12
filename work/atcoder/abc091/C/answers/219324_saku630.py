from collections import defaultdict
n = int(input())
G = defaultdict(list)
rec = []
for i in range(n):
    a, b = map(int, input().split())
    rec.append((i, a, b))


for i in range(n):
    c, d = map(int, input().split())
    for index, p, q in rec:
        if p < c and q < d:
            G[index].append(i + n)
            G[i + n].append(index)


used = [False] * 2 * n
match = [-1] * 2 * n


def dfs(v):
    global used
    used[v] = True
    for u in G[v]:
        w = match[u]
        if w < 0 or not used[w] and dfs(w):
            match[v] = u
            match[u] = v
            return True


ma = 0
for i in range(n):
    if match[i] < 0:
        used = [False] * 2 * n
        if dfs(i):
            ma += 1

print(ma)