from collections import Counter
N = int(input())
c = Counter(list(map(int, input().split())))

ans = 0
for i in c:
  if c[i] < i:
    ans += c[i]
  elif c[i] > i:
    ans += c[i] - i

print(ans)