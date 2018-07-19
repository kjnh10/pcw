n = int(input())
xs = list(sorted(list(map(int, input().split()))))[::-1]

ans = 0
s = 1
for x in xs:
  ans += s * x
  s *= -1
print(ans)