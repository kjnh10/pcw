N, M = [int(_) for _ in input().split()]

conn = [[0] * N for _ in range(N)]
for i in range(M):
    a, b = [int(_) - 1 for _ in input().split()]
    conn[a][b] = conn[b][a] = 1

for i in range(N):
    friend = []
    for j in range(N):
        if conn[i][j] == 1:
            friend.append(j)

    result = []
    for k in friend:
        for l in range(N):
            if conn[k][l] == 0 or i == l:
                continue

            if l not in friend and l not in result:
                result.append(l)

    print(len(result))
