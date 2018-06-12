n = int(input())
a = list(map(int, input().split()))
d = {}
for i in a:
    if i not in d:
        d[i] = 1
    else:
        d[i] += 1
ans = 0
for i in d.keys():
    if i > d[i]:
        ans += d[i]
    else:
        ans += d[i] - i
print(ans)