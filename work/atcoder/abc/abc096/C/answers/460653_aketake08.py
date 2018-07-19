H, W = map(int, input().split())
S = [input() for i in range(H)]
dd = ((0, -1), (-1, 0), (0, 1), (1, 0))
for i in range(H):
    for j in range(W):
        if S[i][j] == '.':
            continue
        for dx, dy in dd:
            nx = j + dx; ny = i + dy
            if 0 <= nx < W and 0 <= ny < H:
                if S[ny][nx] == '#':
                    break
        else:
            print("No")
            exit(0)
print("Yes")

