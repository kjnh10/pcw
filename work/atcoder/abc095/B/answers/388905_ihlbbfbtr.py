N, X = list(map(int, input().split()))
M = [int(input()) for _ in range(N)]

diff = X - sum(M)
ans = N + diff // min(M)
print(ans)
