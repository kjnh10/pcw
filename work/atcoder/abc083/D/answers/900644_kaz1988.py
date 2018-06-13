S =str(input())
if len(S) % 2 == 1:
    a = 1
    b = int((len(S) - 1) / 2)
    while True:
        if b - a < 0:
            break
        if S[b] == S[b + a] and S[b] == S[b - a]:
            a = a + 1
        else:
            break
    c = a + b
    print(c)
else:
    d = 0
    e = int(len(S) / 2 - 1)
    f = S[e]
    if S[e + 1] == f:
        d = d + 1
    while True:
        if e - d < 0:
            break
        if S[e - d] == f and S[e + d + 1] == f:
            d = d + 1
        else:
            break
    g = d + e + 1
    print(g)