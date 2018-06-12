# coding: utf-8
# Your code here!

N=int(input())
    
def dfs(u):
    for v in range(nv):
        if adj[u][v] and not visited[v]:
            visited[v] = True
            if matches[v] is None or dfs(matches[v]):
                matches[v] = u
                return True
    return False
 
#nu, nv, ne = map(int, input().split(' '))
nu=N
nv=N
adj = [[False] * nv for _ in range(nu)]
matches = [None] * nv
count = 0
 
a = []
b = []
for i in range(N):
    x1,y1=[int(i) for i in input().split()]
    a.append(x1)
    b.append(y1)
c = []
d = []
for i in range(N):
    x1,y1=[int(i) for i in input().split()]
    for j in range(N):
        if (x1-a[j])>0 and (y1-b[j])>0:
            adj[i][j] = True
 
for u in range(nu):
    visited = [False] * nv
    if dfs(u): count += 1
 
print(count)

#print([adj])