s = list(input())
x, y = map(int, input().split())
dir, move, dx, dy = 0, 0, [], [abs(y)]
s.append('E')
first = True
fmove = 0
for i in s:
    if i == 'F':
        move += 1
    else:
        if first:
            fmove = move
            first = False
        else:
            if dir % 2 == 0:
                dx.append(move)
            else:
                dy.append(move)
        move = 0
        dir += 1
temp = (-x + fmove)
for i in sorted(dx, reverse=True):
    if temp < 0:
        temp += i
    else:
        temp -= i
adx = temp
temp = 0
for i in sorted(dy, reverse=True):
    if temp < 0:
        temp += i
    else:
        temp -= i
ady = temp
if adx == ady == 0:
    print('Yes')
else:
    print('No')
