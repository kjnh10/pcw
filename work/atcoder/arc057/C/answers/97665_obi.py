A, K = map(int, input().split())

tyou = int(2e12)

cnt = 0
if K == 0:
	cnt = tyou - A
else:
	while A < tyou:
		cnt += 1
		A = A + 1 + K * A

print(cnt)