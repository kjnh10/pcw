n, k = map(int, input().split())
a = list(map(int, input().split()))
t = sum(a[:k])
ans = t
for i in range(n - k):
    t -= a[i]
    t += a[i + k]
    ans += t
print(ans)
