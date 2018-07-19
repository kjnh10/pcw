_ = list(map(int, input().split()))
n = _[0]
a = _[1]
b = _[2]

s = []
d = []
for i in range(0, n):
    _ = input().split()
    s.append(_[0])
    d.append(int(_[1]))

x = 0
for i in range(0, n):
    if d[i] < a:
        if s[i] == 'East':
            x += a
        else:
            x -= a
    elif d[i] <= b and a <= d[i]:
        if s[i] == 'East':
            x += d[i]
        else:
            x -= d[i]
    elif d[i] > b:
        if s[i] == 'East':
            x += b
        else:
            x -= b

if x == 0:
    print(0)
elif x > 0:
    print('East',x)
elif x < 0:
    print('West',abs(x))