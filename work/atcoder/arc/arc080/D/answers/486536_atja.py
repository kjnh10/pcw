h, w = map(int, input().split())
n = int(input())
a = list(map(int, input().split()))
boje = []
for i, x in enumerate(a):
    for j in range(x):
        boje.append(i + 1)
m = [[0 for j in range(w)] for i in range(h)]
cnt = 0
for i in range(h):
    if i % 2 == 0:
        for j in range(w):
            m[i][j] = boje[cnt]
            cnt += 1
    else:
        for j in range(w - 1, -1, -1):
            m[i][j] = boje[cnt]
            cnt += 1
    print(' '.join(map(str, m[i])))
