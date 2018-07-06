n = int(input())
a, b = map(int, input().split())
k = int(input())
p = list(map(int, input().split()))
p.append(a)
p.append(b)
x = len(p)
y = len(set(p))
if x != y:
    print('NO')
else:
    print('YES')
