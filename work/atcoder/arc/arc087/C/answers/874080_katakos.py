from collections import Counter

input()
ac = Counter(map(int, input().split()))
ans = 0

for a, c in ac.items():
    if a > c:
        ans += c
    else:
        ans += c - a

print(ans)
