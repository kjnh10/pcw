N, X = map(int, input().split())
m = []
for _ in range(N):
    m.append(int(input()))

minv = min(m)
diff = X-sum(m)
print(N + diff//minv)