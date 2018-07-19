N, M = list(map(int, input().split()))

graph = [list() for i in range(N+1)]
for i in range(M):
    a, b = tuple(map(int, input().split()))
    graph[a].append(b)
    graph[b].append(a)

pos_flag = False
for u in graph[1]:
    if N in graph[u]:
        pos_flag = True
        break
if pos_flag == True:
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")