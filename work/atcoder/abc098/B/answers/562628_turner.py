n = int(input())
s = list(input())
ans = 0

for i in range(1, n):
  a, b = s[:i], s[i:]
  temp = set(a) & set(b)
  ans = max(ans, len(temp))

print(ans)