n, m = map(int, input().split())
G = [[] for i in range(n)]
E = []
for i in range(m):
    a, b = map(int, input().split())
    G[a-1].append(b-1)
    G[b-1].append(a-1)
    E.append((a-1, b-1))
from collections import deque
def solve(s, t):
    if len(G[s]) == 1 or len(G[t]) == 1:
        return 1
    used = [0]*n
    que = deque()
    used[s] = 1
    for v in G[s]:
        if v == t:
            continue
        used[v] = 1
        que.append(v)
    while que:
        u = que.popleft()
        for v in G[u]:
            if not used[v]:
                used[v] = 1
                que.append(v)
    return sum(used) != n
ans = 0
for a, b in E:
    ans += solve(a, b)
print(ans)
