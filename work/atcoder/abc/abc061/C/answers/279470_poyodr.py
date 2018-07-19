N, K = map(int, input().split())
d = {}
for n in range(N):
    a, b = map(int, input().split())
    d[a] = d.get(a, 0) + b

keys = list(d.keys())
keys.sort()

cnt = 0
for k in keys:
    cnt += d[k]
    if cnt >= K:
        print(k)
        exit()
print(keys[-1])
