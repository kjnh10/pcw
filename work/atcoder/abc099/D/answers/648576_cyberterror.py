N, C = map(int, input().split())
D = []
c = []
for _ in range(C):
    D.append(list(map(int, input().split())))
for _ in range(N):
    c.append(list(map(lambda x : int(x) - 1, input().split())))
colors = [[0] * C for _ in range(3)]
for i in range(N):
    for j in range(N):
        colors[(i+j)%3][c[i][j]] += 1

def calc(choice):
    ans = 0
    for i,v in zip(range(3),choice):
        for ind, cnt in enumerate(colors[i]):
            ans += cnt * D[ind][v]
    return ans
def dfs(lst, depth):
    ret = []
    if depth == 3:
        return calc(lst)
    for v in range(C):
        if v not in lst:
            lst.append(v)
            ret.append(dfs(lst, depth + 1))
            lst.pop()
    return min(ret)
print(dfs([], 0))
