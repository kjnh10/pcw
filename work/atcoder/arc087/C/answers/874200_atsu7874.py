import collections

n = int(input())
a = collections.Counter(list(map(int, input().split())))
cnt = 0
for key in a.keys():
    if a[key] > key:
        cnt += a[key] - key
    elif a[key] < key:
        cnt += a[key]
print(cnt)

