n = int(input())
a = map(int, input().split())
a = sorted(a)
a.reverse()
ans = 0
for i, v in enumerate(a):
    if i % 2 == 0:
        ans += v
print(ans)
