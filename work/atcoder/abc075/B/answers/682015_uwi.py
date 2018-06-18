import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline()

n,m = na()
mp = []
for i in range(n):
    mp.append([_ for _ in ns().strip()])

for i in range(n):
    for j in range(m):
        if  mp[i][j] != '#':
            bo = 0
            for k in range(-1,2):
                for l in range(-1,2):
                    ni = i + k
                    nj = j + l
                    if 0 <= ni < n and 0 <= nj < m and mp[ni][nj] == '#':
                        bo += 1
            mp[i][j] = chr(bo + 48)

for i in mp:
    print("".join(i))
