W, B = map(int, input().split())

WHITE = "."
BLACK = "#"

base_row = (B // 50 + 1) * 2
GRID = [[WHITE if row < base_row else BLACK for _ in range(100)] for row in range(100)]

for i in range(B - 1):
    GRID[2 * (i // 50)][(i % 50) * 2] = BLACK

for i in range(W - 1):
    GRID[2 * (i // 50) + base_row + 1][(i % 50) * 2] = WHITE

print("100 100")
for row in GRID:
    for c in row:
        print(c, end='')
    print()
