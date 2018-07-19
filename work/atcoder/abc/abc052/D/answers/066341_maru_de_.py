N, A, B = map(int, input().split())
X = list(map(int, input().split()))

OPT = [0 for i in range(N)]
for i in range(1, N):
	OPT[i] = OPT[i-1]+min((X[i]-X[i-1])*A, B)
print(OPT[N-1])