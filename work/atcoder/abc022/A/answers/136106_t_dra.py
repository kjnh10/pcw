n, s, t = map(int, input().split())
w = int(input())
day = 1 if s <= w <= t else 0

for i in range(n-1):
    a = int(input())
    w += a
    if s <= w <= t:
        day += 1

print(day)