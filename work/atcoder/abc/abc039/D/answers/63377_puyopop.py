D = tuple(zip((0, 0, 1, 1, 1, -1, -1, -1),
              (1, -1, -1, 0, 1, -1, 0, 1)))

def conv(field, char):
    result = list(map(list, field))
    for x in range(H):
        for y in range(W):
            if field[x][y] == char:
                for dx, dy in D:
                    nx, ny = x + dx, y + dy
                    if not(0 <= nx < H and 0 <= ny < W):
                        continue
                    result[nx][ny] = char
    return tuple(map(tuple, result))

H, W = list(map(int, input().split()))
field = tuple(tuple(input()) for _ in range(H))
deco = conv(field, ".")
if field == conv(deco, "#"):
    print("possible")
    print(*list(map(lambda x: "".join(x), deco)), sep="\n")
else:
    print("impossible")
