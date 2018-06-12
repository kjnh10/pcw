a, b, c = map(int, input().split())
m = max(a, b, c)
s = sum((m - a, m - b, m - c))
if s % 2 == 1:
    print(s // 2 + 2)
else:
    print(s // 2)
