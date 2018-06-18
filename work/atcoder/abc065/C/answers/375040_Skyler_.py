N, M = [int(x) for x in input().split()]
ans = 0
permN = 1
permM = 1

for i in range(N):
	permN = permN * (i + 1) % (10 ** 9 + 7)
for i in range(M):
	permM = permM * (i + 1) % (10 ** 9 + 7)

if abs(N - M) > 1:
	ans = 0
elif abs(N - M) == 1:
	ans = permN * permM % (10 ** 9 + 7)
else:
	ans = 2 * permN * permM % (10 ** 9 + 7)

print(ans)