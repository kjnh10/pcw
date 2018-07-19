# D
from collections import deque
N, M = map(int, input().split())

value_list = [0]*N
done_list = [-1]*N
# -1:any, 0:not_done, 1:done

res = 'Yes'

G = dict()
for i in range(N):
    G[i] = dict()
    
# input
for _ in range(M):
    L, R, D = map(int, input().split())
    G[L-1][R-1] = D
    G[R-1][L-1] = -D
    done_list[L-1] = 0
    done_list[R-1] = 0

# pick one node not resolved
pick = 0

while pick < N and res == 'Yes':
    
    queue = deque([pick])
    done_list[pick] = 1
    value_list[pick] = 0
    
    # BFS
    while len(queue) > 0:
        L = queue.popleft()
        for R in G[L].keys():
            if done_list[R] == 0:
                done_list[R] = 1
                value_list[R] = value_list[L] + G[L][R]
                queue.append(R)
            else:
                if value_list[R] != value_list[L] + G[L][R]:
                    res = 'No'

    # next seed
    while pick < N:
        if done_list[pick] == 0:
            break
        pick += 1
print(res)