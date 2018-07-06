import math
N,A,B = map(int,input().split())
H = [int(input()) for i in range(N)]
Hs = sum(H)
c = A - B
M = math.ceil(Hs / B)

m = 0

while M - m > 1:
	n = (M + m) // 2
	H2 = [H[i] - n * B for i in range(N) if H[i] - n * B > 0]
	cnts = [math.ceil(H2[i] / c) for i in range(len(H2))]
	cnt = sum(cnts)
	if cnt > n:
		m = n
	elif cnt == n:
		M = n
		break
	else:
		M = n
print(M)