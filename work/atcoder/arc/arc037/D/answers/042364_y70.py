def dfs(v,p):
	global edges
	visit[v] |= True
	res = False
	for u in edges[v]:
		if u != p:
			if visit[u] == True:
				return True	
			else:
				res |= dfs(u,v)
	return res

N,M = map(int,input().split())
edges = [[] for _ in range(N)]
for i in range(M):
	u,v = map(int,input().split())
	edges[u-1] += [v-1]
	edges[v-1] += [u-1]

res = 0
visit = [False] * N
for i in range(N):
	if visit[i] == False:
		Closed_cycle = dfs(i,-1)
		if Closed_cycle == False:
			res += 1

print(res)