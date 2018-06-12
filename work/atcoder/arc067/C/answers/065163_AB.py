from collections import Counter
def factorize(n):
	from math import sqrt
	r = int(sqrt(n))
	a = []
	while not n % 2:
		a.append(2)
		n //= 2
	for m in range(3,r+1,2):
		while not n % m:
			a.append(m)
			n //= m
	if n != 1:
		a.append(n)
	return Counter(a)
mod = 10**9 + 7
N = int(input())
c = Counter()
for i in range(2,N+1):
	c += factorize(i)

ans = 1
for i in list(c.values()):
	ans = ans*(i+1)%mod
print(ans)