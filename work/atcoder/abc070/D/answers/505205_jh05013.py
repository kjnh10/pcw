from sys import stdin
input = stdin.readline
n = int(input())
adj = [[] for i in range(n+1)]
for i in range(n-1):
    a, b, c = map(int,input().split())
    adj[a].append((b,c))
    adj[b].append((a,c))
qn, k = map(int,input().split())

from collections import deque
dist = [-1]*(n+1)
dist[k] = 0
Q = deque()
Q.append(k)
while len(Q):
    p = Q.popleft()
    for q,c in adj[p]:
        if dist[q] != -1: continue
        dist[q] = dist[p]+c
        Q.append(q)
for i in range(qn):
    x, y = map(int,input().split())
    print(dist[x]+dist[y])