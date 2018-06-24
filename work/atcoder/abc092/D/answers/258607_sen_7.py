#!/usr/bin/env python3

a, b = map(int, input().split())

h = 98
w = 99
print(h, w)

grid = [["." for i in range(w)] for j in range(h)]

for i in range(h // 2, h):
    for j in range(w):
        grid[i][j] = "#"

def ij_k(k):
    row = (w - 1) // 2
    i = (k // row) * 2 + 1
    j = (k % row) * 2 + 1
    assert 0 < i < h // 2 - 1
    assert 0 < j < w - 1
    return i, j

for k in range(b - 1):
    i, j = ij_k(k)
    grid[i][j] = "#"

for k in range(a - 1):
    i, j = ij_k(k)
    grid[i + h // 2][j] = "."

for i in range(h):
    r = "".join(grid[i])
    print(r)
