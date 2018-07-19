x = int(input())

a = x - 1

b = a % 11

ans = int(a / 11)*2

if b > 5:
    ans += 2
else:
    ans += 1

print(ans)