s = input().strip()
n = len(s)

ansone, anszero = n, n
for i, c in enumerate(s):
    ld, rd = i, n - i - 1
    if c == '1':
        ansone = min(ansone, max(ld, rd))
    else:
        anszero = min(anszero, max(ld, rd))
print(max(ansone, anszero))
