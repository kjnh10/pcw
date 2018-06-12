h, w = map(int, input().split())
f = [' ' * w] + [list(' ' + input().strip() + ' ') for _ in range(h)] + [' ' * w]

for i, l in enumerate(f):
    for j, b in enumerate(l):
        if b == '.':
            c = int(l[j - 1] == '#') + int(l[j + 1] == '#')
            c += f[i - 1][j - 1:j + 2].count('#')
            c += f[i + 1][j - 1:j + 2].count('#')
            l[j] = c
for l in f[1:h + 1]:
    print(''.join(map(str, l[1:w + 1])))
