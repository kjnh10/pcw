n = int(input())
xxx = list(map(int, input().split()))
yyy = sorted(xxx)
h = n // 2
a, b = yyy[h - 1], yyy[h]
for x in xxx:
    if x <= a:
        print(b)
    else:
        print(a)
