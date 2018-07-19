N = int(input())

a, b = [], []
for n in range(N):
    _a, _b = map(int, input().split(' '))
    a.append(_a)
    b.append(_b)

c, d = [], []
for n in range(N):
    _c, _d = map(int, input().split(' '))
    c.append(_c)
    d.append(_d)

def dfs(v, visited):
    """
    :param v: X側の未マッチングの頂点の1つ
    :param visited: 空のsetを渡す（外部からの呼び出し時）
    :return: 増大路が見つかればTrue
    """
    for u in edges[v]:
        if u in visited:
            continue
        visited.add(u)
        if matched[u] == -1 or dfs(matched[u], visited):
            matched[u] = v
            return True
    return False

# 標準入力からのグラフ読み取り
edges = [set() for _ in range(N)]
matched = [-1] * N

# 隣接行列
M = [[0 for _ in range(N)] for _ in range(N)]
for i in range(N):
    for j in range(N):
        if a[i] < c[j] and b[i] < d[j]:
            edges[i].add(j)

# 増大路発見に成功したらTrue(=1)。合計することでマッチング数となる
print(sum(dfs(s, set()) for s in range(N)))