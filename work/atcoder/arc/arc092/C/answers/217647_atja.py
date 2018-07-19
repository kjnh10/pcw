n = int(input())
a = []
for i in range(n):
    x, y = map(int, input().split())
    a.append((x, y))
b = []
for i in range(n):
    x, y = map(int, input().split())
    b.append((x, y))
sus = [[] for i in range(n)]
for i in range(n):
    for j in range(n):
        if a[i][0] < b[j][0] and a[i][1] < b[j][1]:
            sus[i].append(j)

conn = [-1 for i in range(n)]

def dfs(x):
    global bio
    bio[x] = 1
    for y in sus[x]:
        if conn[y] == -1:
            conn[y] = x
            return 1
        if bio[conn[y]] == 0 and dfs(conn[y]):
            conn[y] = x
            return 1
    return 0

s = 0
for i in range(n):
    bio = [0 for j in range(n)]
    s += dfs(i)
print(s)
