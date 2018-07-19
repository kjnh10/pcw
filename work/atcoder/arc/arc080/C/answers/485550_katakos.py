input()
c1, c2, c4 = 0, 0, 0
for a in map(int, input().split()):
    if a & 1:
        c1 += 1
    elif a & 2:
        c2 += 1
    else:
        c4 += 1

if c2:
    print('Yes' if c4 >= c1 else 'No')
else:
    print('Yes' if c4 and c4 + 1 >= c1 else 'No')
