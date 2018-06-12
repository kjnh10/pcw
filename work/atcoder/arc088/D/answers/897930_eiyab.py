s = input()

if len(s) % 2 == 0:
    c = 0
    m = len(s) // 2 - 1
    x = s[m]
    while c <= m and x == s[m-c] and x == s[m+1+c]:
        c += 1
    print(len(s) // 2 + c)
else:
    c = 0
    m = len(s) // 2
    x = s[m]
    while c < m and x == s[m-1-c] and x == s[m+1+c]:
        c += 1
    print(len(s) // 2 + c + 1)