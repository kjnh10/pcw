a, b = map(int, input().split())
i = a
ans = 0
while i <= b:
  ans += 1
  i *= 2
  
print(ans)