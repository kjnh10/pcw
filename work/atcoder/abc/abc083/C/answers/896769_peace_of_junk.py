x, y = map(int, input().split())
ans = 0
a = x
while a <= y:
    a = 2*a
    ans += 1
print(ans)