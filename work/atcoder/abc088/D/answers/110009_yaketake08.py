from collections import deque
H, W = map(int, input().split())
S = [input() for i in range(H)]
C = sum(s.count('.') for s in S)

dd = ((-1, 0), (0, -1), (1, 0), (0, 1))
que = deque([(0, 0, 0)])
used = {(0, 0)}

res = None
while que:
    s, t, cost = que.popleft()
    if s == H-1 and t == W-1:
        res = cost
        break
    for di, dj in dd:
        ni = s + di; nj = t + dj
        if (not 0 <= ni < H) or (not 0 <= nj < W) or S[ni][nj] == '#' or (ni, nj) in used:
            continue
        used.add((ni, nj))
        que.append((ni, nj, cost + 1))
if res:
    print(C - 1 - res)
else:
    print(-1)
