def find(x):
    if parent[x] != x:
        parent[x] = find(parent[x])
    return parent[x]

def union(x, y):
    x = find(x)
    y = find(y)
    if x == y: return
    if rank[x] < rank[y]:
        parent[x] = y
    else:
        parent[y] = x
        if rank[x] == rank[y]:
            rank[x] += 1


N, M = map(int, input().split())
ps = list(map(lambda x: int(x) - 1, input().split()))

parent = [i for i in range(N)]
rank = [0] * N

for i in range(M):
    x, y = map(int, input().split())
    union(x - 1, y - 1)

for i in range(N):
    find(i)

ans = 0
for i in range(N):
    if parent[i] == parent[ps[i]]:
        ans += 1

print(ans)
