n = int(input().strip())
d, x = map(int, input().strip().split(" "))
ans = 0
for _ in range(n):
    ans += 1
    ans += (d - 1) // int(input().strip())
print(ans + x)
