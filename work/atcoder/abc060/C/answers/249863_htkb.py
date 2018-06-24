n, t = map(int, input().split())
a = [int(s) for s in input().split()]
total = 0
for i in range(1, n):
    total += min(t, a[i]-a[i-1])
total += t
print(total)