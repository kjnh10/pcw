

def dfs(graph, start, visited):
    if visited[start] != -99999:
        return True
    
    stack = [start]
    visited[start] = 0
    while stack:
        label = stack.pop()
        for nextnode, distance in graph[label]:
            if visited[nextnode] == -99999:
                stack.append(nextnode)
                visited[nextnode] = visited[label] + distance
            elif visited[nextnode] != visited[label] + distance:
                return False
    return True

N, M = (int(i) for i in input().split())  

graph = [[] for i in range(N+1)]

for i in range(M):
    L, R, D = (int(i) for i in input().split())
    graph[L].append((R, D))
    graph[R].append((L, -1 * D))


visited = [-99999 for i in range(N+1)]

flag = True
for i in range(1, N + 1):
    ans = dfs(graph, i, visited)
    if not ans:
        flag = False
        break

if flag:
    print('Yes')
else:
    print('No')

