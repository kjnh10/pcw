n, z, w = list(map(int, input().split()))
a = list(map(int, input().split()))

ans = max(abs(a[n-1] - w), abs(a[n-1] - a[n-2]))
print(ans)