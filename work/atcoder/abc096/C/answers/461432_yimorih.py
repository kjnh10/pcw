h, w = map(int, input().split())
s = [input() for _ in range(h)]
s = ['.'*(w+2)] + ['.'+l+'.' for l in s] + ['.'*(w+2)]
d = [0,1,0,-1,0]
check = True
for i in range(1, h+1):
    for j in range(1, w+1):
        if s[i][j] == '#':
            f = False
            for k in range(4):
                di = i+d[k+1]
                dj = j+d[k]
                if s[di][dj] == '#':
                    f = True
                    break
            if not f:
                check = False
                break
    if not check:
        break
print('Yes' if check else 'No')
