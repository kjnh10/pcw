N, K = map(int, input().split())
ans = 0
for b in range(N + 1)[K:]:
	if b == 0:
		continue
	ans += (b - K) * int(N / b)
	if N % b >= K and K > 0:
		ans += N % b - K + 1
	elif N % b >= K:
		ans += N % b - K
print(ans)