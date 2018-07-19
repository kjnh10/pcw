def f(x, n, M):
	#print("x:{} n:{} M:{}".format(x, n, M))
	if n == 0:
		return 1
	ret = f(x*x%M, n//2, M)
	if n & 1:
		ret = ret * x % MOD
	return ret

A = int(input())
B = int(input())
C = int(input())
MOD = 1000000007
c = ((B*C%MOD - (A*B%MOD) + MOD)%MOD)*f((A*C%MOD-(B*C)%MOD+A*B%MOD+MOD)%MOD, MOD-2, MOD)
r = ((B*C%MOD - (A*C%MOD) + MOD)%MOD)*f((A*B%MOD-(B*C)%MOD+A*C%MOD+MOD)%MOD, MOD-2, MOD)
print("{} {}".format(r%MOD, c%MOD))
