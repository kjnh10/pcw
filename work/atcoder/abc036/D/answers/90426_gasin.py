# -*- coding: utf-8 -*-

mod = 10**9+7

n = int(input())
e = [[] for i in range(n)]
par = [-1 for i in range(n)]
dp = [-1 for i in range(n*2)]

def f(z):
	for i in range(len(e[z])):
		if par[z] != e[z][i]:
			par[e[z][i]] = z
			f(e[z][i])
		
def ff(y,z):
	if dp[y+z*n] != -1:
		return dp[y+z*n]
	cnt = 1
	for i in range(len(e[y])):
		if e[y][i] == par[y]:
			continue
		if z == 0:
			cnt = cnt*(ff(e[y][i],1)+ff(e[y][i],0))
		else:
			cnt = cnt*ff(e[y][i],0)
		cnt = cnt%mod
	dp[y+z*n] = cnt
	return cnt
	
for i in range(n-1):
	a, b = map(int,input().split())
	a = a-1
	b = b-1
	e[a].append(b)
	e[b].append(a)
f(0)
print((ff(0,0)+ff(0,1))%mod)
