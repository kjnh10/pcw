n = int(input())
s = [input() for i in range(n)]
m = int(input())
t = [input() for i in range(m)]
ans = 0
temp = set(s)
for i in temp:
  if s.count(i) - t.count(i) > ans:
    ans = s.count(i) - t.count(i)

print(ans)