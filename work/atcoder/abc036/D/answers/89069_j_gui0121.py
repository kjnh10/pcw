n = int(input())
vv = [[] for i in range(n)] 
MOD = 1000000007
for i in range(n-1):
	a,b = map(int,input().split())
	a-=1
	b-=1
	vv[a].append(b)
	vv[b].append(a)

dp = [[-1] * 2 for i in range(n)]

def calc(x, y, z):
	if dp[x][z] >= 0:
		return dp[x][z]
	a = 1
	b = 1
	for i in vv[x]:
		if i == y:
			continue
		c = calc(i, x, 0)
		d = calc(i, x, 1)
		a = (a * c) % MOD
		b = (b * (c + d)) % MOD
	dp[x][0] = b
	dp[x][1] = a
	return dp[x][z]

print(((calc(0,-1,0)+calc(0,-1,1))%MOD))