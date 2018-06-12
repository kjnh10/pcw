n = int(input())

ans = 1

for i in range(n):
    ans *= (i + 1)
    ans %= (1000000000 + 7)

print(ans)
