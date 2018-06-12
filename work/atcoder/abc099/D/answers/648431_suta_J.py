# 1. 入出力 (二次元配列)

N, C = map(int, input().split())

D = [ list(map(int, input().split())) for _ in range(C) ]
col = [ list(map(int, input().split())) for _ in range(N) ]

ans = 1 << 60
info = [ [0 for j in range(C)] for i in range(3) ]

for i in range(N):
    for j in range(N):
        mod = (i + j) % 3
        info[mod][ col[i][j] - 1 ] += 1

for i in range(C):
    for j in range(C):
        for k in range(C):
            if i == j or j == k or k == i:
                continue

            temp = 0
            lst = [i, j, k]

            for x in range(3):
                for y in range(C):
                    temp += D[y][ lst[x] ] * info[x][y]

            ans = min(ans, temp)
            # print(lst, temp)

print(ans)