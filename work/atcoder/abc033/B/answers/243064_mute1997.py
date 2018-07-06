n = int(input())
s = []
p = []
for i in range(0, n):
    _ = input().split()
    s.append(_[0])
    p.append(int(_[1]))

def slv(p, s):
    h = sum(p) / 2
    for i in range(0, n):
        if h < p[i]:
            print(s[i])
            return
    print('atcoder')

slv(p, s)