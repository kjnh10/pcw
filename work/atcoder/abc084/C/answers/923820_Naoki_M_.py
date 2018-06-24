n = int(input())
csf = [tuple(map(int, input().split())) for _ in range(n - 1)]

for i in range(n):
    t = 0
    for j in range(i, n - 1):
        c, s, f = csf[j]
        t = max(s, ((t + f - 1) // f) * f) + c
    print(t)