N = int(input())
A = []
B = []
C = []
D = []
for i in range(N):
    a, b = map(int, input().split())
    A.append(a)
    B.append(b)
for i in range(N):
    c, d = map(int, input().split())
    C.append(c)
    D.append(d)

G = [[] for i in range(2 * N + 10)]
for i in range(N):
    for j in range(N):
        if A[i] < C[j] and B[i] < D[j]:
            G[i].append(N + j)
            G[N + j].append(i)

used = [False for i in range(2 * N + 10)]
match = [-1 for i in range(2 * N + 10)]

def dfs(v):
    used[v] = True
    for i in range(len(G[v])):
        u = G[v][i]
        w = match[u]
        if w < 0 or not used[w] and dfs(w):
            match[v] = u
            match[u] = v
            return True
    return False

ans = 0
for v in range(N):
    if match[v] < 0:
        for i in range(2 * N + 10):
            used[i] = False
        if dfs(v):
            ans += 1
print(ans)
