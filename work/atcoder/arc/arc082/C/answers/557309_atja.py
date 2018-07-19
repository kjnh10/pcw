n = int(input())
a = list(map(int, input().split()))
f = [0 for i in range(100005)]
for x in a:
    f[x + 1] += 1
maks = 0
for i in range(1, 100002):
    maks = max(maks, f[i - 1] + f[i] + f[i + 1])
print(maks)