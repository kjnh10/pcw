w = ['esare', 'maerd', 'remaerd', 'resare']
S = input()[::-1]
i = 0
while i < len(S):
    find = False
    for j in range(4):
        if S.startswith(w[j], i):
            find = True
            i += len(w[j])
            break
    if not find:
        break

if i >= len(S):
    print('YES')
else:
    print('NO')
