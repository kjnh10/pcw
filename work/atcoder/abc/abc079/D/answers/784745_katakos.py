h, w = map(int, input().split())
costs = [list(map(int, input().split())) for _ in range(10)]

for k in range(10):
    for i in range(10):
        for j in range(10):
            costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j])

ans = 0
for _ in range(h):
    for n in map(int, input().split()):
        if n == -1:
            continue
        ans += costs[n][1]

print(ans)
