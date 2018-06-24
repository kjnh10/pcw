n = int(input())
a = [int(i) for i in input().split()]

ans1 = ans2 = 0
s = s2 = a[0]
if a[0] <= 0:
    s = 1
    ans1 = -a[0] + 1
if a[0] >= 0:
    s2 = -1
    ans2 = a[0] + 1

for i in range(1, len(a)):
    s += a[i]
    if i % 2 == 1 and s >= 0:
        ans1 += s + 1
        s = -1
    elif i % 2 == 0 and s <= 0:
        ans1 += -s + 1
        s = 1
    s2 += a[i]
    if i % 2 == 0 and s2 >= 0:
        ans2 += s2 + 1
        s2 = -1
    elif i % 2 == 1 and s2 <= 0:
        ans2 += -s2 + 1
        s2 = 1

print(min(ans1, ans2))
