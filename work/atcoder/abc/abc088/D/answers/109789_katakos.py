from collections import deque


def dfs(field):
    q = deque([(0, 0, 1)])
    visited = [[False] * w for _ in range(h)]
    while q:
        i, j, d = q.popleft()
        if i == h - 1 and j == w - 1:
            return d
        if visited[i][j]:
            continue
        visited[i][j] = True
        if i > 0 and field[i - 1][j] == '.':
            q.append((i - 1, j, d + 1))
        if i < h - 1 and field[i + 1][j] == '.':
            q.append((i + 1, j, d + 1))
        if j > 0 and field[i][j - 1] == '.':
            q.append((i, j - 1, d + 1))
        if j < w - 1 and field[i][j + 1] == '.':
            q.append((i, j + 1, d + 1))
    else:
        return -1


h, w = map(int, input().split())
field = [input() for _ in range(h)]
init_black = sum(r.count('#') for r in field)
res = dfs(field)
if res == -1:
    print(-1)
else:
    print(h * w - res - init_black)
