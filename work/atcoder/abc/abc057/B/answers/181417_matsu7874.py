def md(a,b,c,d):
    return abs(a-c) + abs(b-d)
n,m = map(int, input().split())
s = []
for i in range(n):
    y,x = map(int, input().split())
    s.append((y,x))
c = []
for i in range(m):
    y,x = map(int, input().split())
    c.append((y,x))
for i in range(n):
    min_j = 0
    min_d = float('inf')
    for j in range(m):
        d = md(s[i][0], s[i][1], c[j][0], c[j][1])
        if min_d > d:
            min_j = j
            min_d = d
    print(min_j+1)


