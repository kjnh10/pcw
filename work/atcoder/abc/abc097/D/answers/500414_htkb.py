N, M = map(int, input().split())
a = [0]+list(map(int, input().split()))
edges = [[] for _ in [0]*(N+1)]
for _ in [0]*M:
    x, y = map(int, input().split())
    edges[x].append(y)
    edges[y].append(x)

result = 0
visited = set()
for i in range(1, N):
    if i in visited:
        continue
    current = set()
    q = [i]
    while q:
        cur = q.pop()
        for dest in edges[cur]:
            if dest not in current:
                q.append(dest)
                current.add(dest)
    result += len(current & set(a[n] for n in current))

    visited |= current
current = set(range(1, N+1)) - visited
for n in current:
    result += a[n] == n
print(result)