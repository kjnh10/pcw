A, B = [int(_) for _ in input().split()]

#A, B = 500, 400
pat = "#."

if A > B:
    A, B = B, A
    pat = pat[1] + pat[0]

h, w = 100, 100

rows = [[1] * w for _ in range(h)]

i = 0
x = 0
y = 3
while i < B:
    rows[y][x] = 0
    rows[y][x + 1] = 0
    rows[y][x + 2] = 0
    x += 4
    if x >= w:
        x = 0
        y += 4
    i += 1

i = 1
x = 0
y = 1
while i < A:
    rows[y][x] = 0
    rows[y][x + 1] = 0
    rows[y][x + 2] = 0
    rows[y + 1][x] = 0
    rows[y + 1][x + 2] = 0
    x += 4
    if x >= w:
        x = 0
        y += 4
    i += 1

print(h, w)
for y, row in enumerate(rows):
    print("".join(pat[c] for c in row))
