def gcd(a, b):
	if b == 0:
		return a
	return gcd(b, a % b)
n = int(input())
a = [int(input()) for i in range(n)]
ans = 1
for i in a:
	ans = ans * i // gcd(ans, i)
print(ans)

