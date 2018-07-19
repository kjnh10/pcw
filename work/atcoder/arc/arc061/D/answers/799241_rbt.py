#!/usr/bin/env python3

H, W, N = map(int, input().split())
dct = {}
for i in range(N):
    a, b = map(lambda x: int(x) - 1, input().split())
    for x in range(3):
        for y in range(3):
            if 0 <= a - y < H - 2 and 0 <= b - x < W - 2:
                p = (a - y, b - x)
                dct[p] = 1 if (p not in dct) else dct[p] + 1

cnt = [0] * 10
for n in dct.values():
    cnt[n] += 1
cnt[0] = (H - 2) * (W - 2) - len(dct)

for i in cnt:
    print(i)
