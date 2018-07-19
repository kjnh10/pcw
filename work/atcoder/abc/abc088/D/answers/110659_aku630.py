from collections import deque
H, W = map(int, input().split())
INF = float("inf")
d = [[INF] * W for _ in range(H)]
T = [[""] * W for _ in range(H)]
sx, sy = 0, 0
gx, gy = H - 1, W - 1
num = 0
for i in range(H):
    a = input()
    for j in range(W):
        T[i][j] = a[j]
    num += a.count("#")


def bfs():
    que = deque()
    que.append((sx, sy))
    d[sx][sy] = 0

    while len(que):
        x, y = que.popleft()
        if x == gx and y == gy:
            break
        for dx, dy in [(0, 1), (1, 0), (-1, 0), (0, -1)]:
            nx, ny = x + dx, y + dy

            if 0 <= nx < H and 0 <= ny < W and T[nx][ny] != "#" and d[nx][ny] == INF:
                que.append((nx, ny))
                d[nx][ny] = d[x][y] + 1

    return d[gx][gy]


ans = bfs()
if ans < INF:
    print(H * W - ans - num - 1)
else:
    print(-1)
