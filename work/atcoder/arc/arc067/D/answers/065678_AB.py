N, A, B = map(int, input().split())
x = [int(i) for i in input().split()]
D = [x[i]-x[i-1] for i in range(1,N)]
ans = 0
for d in D:
	ans += min(A*d,B)
print(ans)