N, M = map(int, input().split())
c = [0] * N

for _ in range(M):
    a, b = map(int, input().split())
    c[a - 1] += 1
    c[b - 1] += 1

print(*c, sep='\n')
