n, z, w = map(int, input().split())
a = list(map(int, input().split()))

if n == 1:
    ans = abs(a[0] - w)
else:
    a1 = abs(a[-1] - w)
    a2 = abs(a[-2] - a[-1])
    ans = max(a1, a2)

print(ans)
