n, l = map(int, input().split(' '))
s = [input() for i in range(n)]

s.sort()
for t in s:
    print(t, end='')
print()