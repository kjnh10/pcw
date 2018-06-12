n = int(input())
r, s = 2, n
a = []
for i in range(r):
    a.append(list(map(int, input().split())))

jagoda = [[-1 for j in range(s)] for i in range(r)]

# Pocetno polje
jagoda[0][0] = a[0][0]

# Prvi redak
for j in range(1, s):
    jagoda[0][j] = jagoda[0][j - 1] + a[0][j]

# Prvi stupac
for i in range(1, r):
    jagoda[i][0] = jagoda[i - 1][0] + a[i][0]

# Ostala polja
for i in range(1, r):
    for j in range(1, s):
        jagoda[i][j] = max(jagoda[i - 1][j], jagoda[i][j - 1]) + a[i][j]

print(jagoda[-1][-1])
