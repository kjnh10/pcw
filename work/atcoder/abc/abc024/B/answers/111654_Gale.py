n, t = map(int, input().split())
a = [int(input()) for i in range(n)]
ans = t

for i in range(1, n):
    ans += t
    if a[i] <= a[i - 1] + t:
        ans = ans - (a[i - 1] + t - a[i])

print(ans)
