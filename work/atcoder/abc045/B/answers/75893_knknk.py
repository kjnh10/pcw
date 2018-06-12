
s = { 'a':input(), 'b':input(), 'c':input() }
n = 'a'
while True:
    if 0 < len(s[n]):
        o = s[n][0]
        s[n] = s[n][1:]
        n = o
    else:
        print(n.upper())
        break