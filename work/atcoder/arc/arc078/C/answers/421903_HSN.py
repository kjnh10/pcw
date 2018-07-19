n = int(input())
a = list(map(int, input().split()))
s = sum(a)

tot = 0
ans = 1 << 62
for i in range(len(a) - 1):
    tot += a[i]
    ans = min(abs(tot - (s - tot)), ans)
print(ans)
