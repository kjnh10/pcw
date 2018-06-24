a,b,c,d = [int(i) for i in input().split()]

ans = 0
for i in range(101):
    if i in range(a,b) and i in range(c,d):
        ans += 1

print(ans)
