MOD = 10**9 + 7
N,K = map(int,input().split())

fact = [0] * 501
rfact = [0] * 501

def extgcd(a,b):
	def extgcd_core(a,b):
		if b == 0:
			return 1, 0, a
		else:
			x, y, q = extgcd_core(b, a % b)
			x, y = y, (x - a // b * y)
			return x, y, q
	x, y, q = extgcd_core(a, b)
	if x < 0:
		x = x % b
		y = -(a * x - 1) // b
	return x, y, q

def mod_inv(a, M):
	x, y, q = extgcd(a, M)
	return (M + x % M) % M

def init_modC():
	global fact, rfact, MOD
	fact[0] = 1
	rfact[0] = 1
	for i in range(1,501):
		fact[i] = (fact[i-1] * i) % MOD
		rfact[i] = (rfact[i-1] * mod_inv(i, MOD)) % MOD

def MODnCk(n,k):
	global fact, rfact, MOD
	res = (((fact[n] * rfact[n-k]) % MOD) * rfact[k]) % MOD
	return res

init_modC()
res = 0

if N > K:
	res = MODnCk(N - 1 + K , K)
elif N == K:
	res = 1
else: # if N < K:
	K %= N
	res = MODnCk(N,K) 

print(res)