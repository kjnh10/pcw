s = input()
n = len(s)-1
ans = 0
for i in range(1<<n):
    k = 0
    for j in range(n):
        if 1&(i>>j):
            ans += int(s[k:(j+1)])
            k = j+1
    ans += int(s[k:])
print(ans)
