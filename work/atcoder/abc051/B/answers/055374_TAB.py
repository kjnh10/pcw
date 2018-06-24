K, S = map(int, input().split())
ans = 0
for x in range(min(K,S)+1):
	for y in range(min(K,S)+1):
		if 0 <= S - x - y <= K:
			ans += 1
print(ans)