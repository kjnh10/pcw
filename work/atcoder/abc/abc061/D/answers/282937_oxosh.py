# D
from collections import deque

# create graph
G = dict()
G_inv = dict()
N, M = map(int, input().split())
for n in range(1, N+1):
    G[n] = dict()
    G_inv[n] = dict()

for _ in range(M):
    a, b, c = map(int, input().split())
    G[a][b] = c
    G_inv[b][a] = c

# value
values = [-1000000000*2000]*(N+1)
values[1] = 0

reachable = [0]*(N+1)
reachable[N] = 1
# find reachble points
dr = deque([N])
while len(dr) > 0:
    b = dr.popleft()
    for a in G_inv[b].keys():
        if reachable[a] == 0:
            reachable[a] = 1
            dr.append(a)

# BFS
inc_cnt = 0
d = deque([1])
while len(d) > 0:
    a = d.popleft()
    for b in G[a].keys():
        if values[b] < values[a] + G[a][b] and reachable[b] == 1:
            values[b] = values[a] + G[a][b]
            inc_cnt += 1
            d.append(b)
    if inc_cnt > 2000:
        break
if inc_cnt > 1000:
    print('inf')
else:
    print(values[N])