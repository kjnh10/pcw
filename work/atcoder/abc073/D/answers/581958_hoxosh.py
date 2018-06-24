# D
from itertools import permutations
from collections import deque

N, M, R = map(int, input().split())
r_list = list(map(int, input().split()))



# read graph
G = dict()
for i in range(N):
    G[i+1] = dict()
for _ in range(M):
    A, B, C = map(int, input().split())
    G[A][B] = C
    G[B][A] = C

# minimum length
dist_list = [[0]*R for _ in range(R)]

for i in range(R):
    # BFS
    que = deque([r_list[i]])
    d_list_i = [M*100000+1]*(N+1)
    d_list_i[r_list[i]] = 0
    while len(que) > 0:
        s = que.popleft()
        for t in G[s].keys():
            if d_list_i[s] + G[s][t] < d_list_i[t]:
                d_list_i[t] = d_list_i[s] + G[s][t]
                que.append(t)
            else:
                pass
        
    for j in range(R):
        dist_list[i][j] = d_list_i[r_list[j]]
    
# power forever    
perms = list(permutations(range(R)))

res = (M*100000+1)*R
for p in perms:
    res_ = 0
    for i in range(R-1):
        res_ += dist_list[p[i]][p[i+1]]
    res = min(res, res_)
    
# print(G)
# print(dist_list)
print(res)