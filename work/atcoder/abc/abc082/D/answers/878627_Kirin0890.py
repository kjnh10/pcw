s = list(input(),)
x, y = map(int, input().split())
dir, move, fmove, dx, dy = 0, 0, 0, [], [abs(y)]
s.append('E')
first = True
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

def to0(d, ini):
    ad = ini
    for i in sorted(d, reverse=True):
        if ad < 0:
            ad += i
        else:
            ad -= i
    return ad
adx, ady = to0(dx, -x + fmove), to0(dy, 0)
if adx == ady == 0:
    print('Yes')
else:
    print('No')
