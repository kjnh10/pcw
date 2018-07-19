a = input()
b = input()
c = input()

t = 'a'
win = 'A'
while(True):
    if t == 'a':
        if len(a) == 0:
            win = 'A'
            break
        t = a[0]
        a = a[1:]
    elif t == 'b':
        if len(b) == 0:
            win = 'B'
            break
        t = b[0]
        b = b[1:]
    else:
        if len(c) == 0:
            win = 'C'
            break
        t = c[0]
        c = c[1:]

print(win)
