N, M = map(int, input().split())
P = [list(map(int, input().split())) for i in range(N)]

ans = 0
for a in [-1, 1]:
    for b in [-1, 1]:
        for c in [-1, 1]:
            s = []
            for x, y, z in P:
                s.append(a*x + b*y + c*z)
            s.sort(reverse=1)
            ans = max(ans, sum(s[:M]))
print(ans)