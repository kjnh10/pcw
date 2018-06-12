K = int(input())

def invGCD(a, b, cnt):
	if cnt == 0:
		return (a, b)
	else:
		return invGCD(a+b, a, cnt-1)

ans = invGCD(4, 2, K-1)
print(ans[0],ans[1])
