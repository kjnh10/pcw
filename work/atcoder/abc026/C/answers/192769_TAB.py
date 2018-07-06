N = int(input())
B = []
for i in range(N-1):
	B.append(int(input()))

buka = [[] for _ in range(N)]
for i in range(N-1):
	buka[B[i]-1].append(i+1)

income = [-1]*N

for i in range(N):
	if not buka[i]:
		income[i] = 1
while income[0] < 0:
	for i in range(N):
		if income[i] > 0:
			continue
		f = 0
		M = 0
		m = 10**9
		for b in buka[i]:
			if income[b] > 0:
				M = max(M,income[b])
				m = min(m,income[b])
			else:
				f = 1
				break
		if not f:
			income[i] =  m + M + 1
print(income[0])