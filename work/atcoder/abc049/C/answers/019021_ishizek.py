s = input()

words = ['dream','dreamer','erase','eraser']

while len(s) > 4:
    if s[-5:] == 'dream':
        s = s[:-5]
        continue
    elif s[-7:] == 'dreamer':
        s = s[:-7]
        continue
    elif s[-5:] == 'erase':
        s = s[:-5]
        continue
    elif s[-6:] == 'eraser':
        s = s[:-6]
        continue
    else:
        break

if len(s) > 0:
    print('NO')
else:
    print('YES')