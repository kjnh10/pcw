n = int(input())
min_b = float('inf')
sa = 0
for _ in range(n):
    a, b = map(int, input().split())
    if a - b > 0:
        min_b = min(min_b, b)
    sa += a
if min_b == float('inf'):
    print(0)
else:
    print(sa - min_b)
