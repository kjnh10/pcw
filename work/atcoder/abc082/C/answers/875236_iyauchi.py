import collections

num = int(input())
val = [int(x) for x in input().split()]

cnt = collections.Counter(val)
res = 0
for x in cnt:
    if cnt[x] > x:
        res += cnt[x] - x
    elif cnt[x] < x:
        res += cnt[x]

print(res)