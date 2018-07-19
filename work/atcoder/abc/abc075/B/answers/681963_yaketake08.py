h, w = map(int, input().split())
S = [list(input()) for i in range(h)]
for i in range(h):
    for j in range(w):
        if S[i][j] == '#':
            continue
        cnt = 0
        for dx in [-1, 0, 1]:
            for dy in [-1, 0, 1]:
                if not 0 <= i+dy < h or not 0 <= j+dx < w:
                    continue
                if S[i+dy][j+dx] == '#':
                    cnt += 1
        S[i][j] = str(cnt)
for s in S:
    print("".join(s))