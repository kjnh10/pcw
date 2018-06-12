from collections import Counter
n = int(input())
for i in range(n):
	if not i:
		c0 = Counter(input())
	else:
		c = Counter(input())
		for l in c0.keys():
			c0[l] = min(c0[l], c[l])
k = sorted(c0.keys())
ans = ""
for l in k:
	ans += l*c0[l]
print(ans)
