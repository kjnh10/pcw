n = int(input())
a = list(map(int, input().split()))
a.sort()
cnt = [0 for i in range(100)]
for i in range(n):
    cnt[a[i]//400] += 1
mi = max(1, sum([1 if cnt[i]>0 else 0 for i in range(8)]))
ma = sum([1 if cnt[i]>0 else 0 for i in range(8)]) + sum(cnt[8:])
print(mi, ma)
