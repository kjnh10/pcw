n, t = map(int, input().split())
time = [0 for i in range(2000001)]

for j in range(n):
    a = int(input())
    time[a] += 1
    time[a + t] -= 1

for k in range(1, 2000001):
    time[k] += time[k - 1]

ans = 0
for l in time:
    if l > 0:
        ans += 1
print(ans)
