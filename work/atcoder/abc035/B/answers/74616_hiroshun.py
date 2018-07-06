s = input()
t = int(input())
x = abs(s.count('L') - s.count('R'))
y = abs(s.count('U') - s.count('D'))
q = s.count('?')
if t == 1:
    print(x + y + q)
else:
    if x + y >= q:
        print(x + y - q)
    else:
        print((x + y + q) % 2)
