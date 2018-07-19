a, b, c, k = map(int, input().split())
s, t = map(int, input().split())
ans = s * a + t * b
if k <= s + t:
    ans -= (s + t) * c
print(ans)