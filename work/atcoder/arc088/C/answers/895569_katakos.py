x, y = map(int, input().split())
ans = 1
while True:
    x <<= 1
    if x > y:
        break
    ans += 1
print(ans)
