import heapq

n, m = map(int, input().split())
graph = [[] for i in range(n)]
for i in range(m):
    l, r, d = map(int, input().split())
    graph[l-1].append((r-1,d))
    graph[r-1].append((l-1,-d))


visited = [False for i in range(n)]
pos = [0 for i in range(n)]

for i in range(n):
    if visited[i]:
        continue
    hq = [(i, 0)]
    while hq:
        v, p = heapq.heappop(hq)
        if visited[v]:
            if p != pos[v]:
                print("No")
                exit()
            continue
        visited[v] = True
        pos[v] = p
        for nv, d in graph[v]:
            if visited[nv]:
                if pos[nv] != p + d:
                    print('No')
                    exit()
                continue
            heapq.heappush(hq, (nv, p+d))
print('Yes')


