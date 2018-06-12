
s = input()

n = len(s) - 1
ans = 0
for mask in range(0, 1 << n):
    num = int(s[0])
    cur = 0
    for i in range(0, n):
        if mask & (1 << i):
            cur += num
            num = 0
        num = num * 10 + int(s[i + 1])
    cur += num
    ans += cur

print(ans)

