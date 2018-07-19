H,W = map(int,input().split())
src = [input() for i in range(H)]

dxy = [(-1,0),(0,-1),(1,0),(0,1)]
for y in range(H):
    for x in range(W):
        if src[y][x] == '.': continue
        for dx,dy in dxy:
            nx,ny = x+dx,y+dy
            if not 0 <= nx < W: continue
            if not 0 <= ny < H: continue
            if src[ny][nx] == '#':
                break
        else:
            print('No')
            exit()
print('Yes')
