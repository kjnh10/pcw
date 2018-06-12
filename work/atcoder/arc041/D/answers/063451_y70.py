dy = [-1, 0, 1, 0]
dx = [ 0, 1, 0,-1]
INF = 10**10

N,M = map(int,input().split())
b = []
for i in range(N):
	b.append(list(map(int,input())))

a = [[0] * M for _ in range(N)]
for i in range(1,N-1):
	for j in range(1,M-1):
		curr = INF
		for k in range(4):
			curr = min(curr, b[i + dy[k]][j + dx[k]])
		if curr == 0:
			continue
		a[i][j] += curr
		for k in range(4):
			b[i + dy[k]][j + dx[k]] -= curr

for i in range(N):
	print("".join(map(str,a[i])))