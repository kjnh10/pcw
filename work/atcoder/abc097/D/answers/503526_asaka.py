import collections
n,m = map(int,input().split())
p = list(map(int,input().split()))
base = 0
basemap = []
for i in range(n):
	if (i+1) == p[i]:
		base += 1
		basemap.append(i+1)

branch = dict()
for i in range(1,n+1):
	branch[i] = []

for i in range(m):
	x,y = map(int,input().split())
	branch[x].append(y)
	branch[y].append(x)
compare = [0 for i in range(n+1)]
for i in range(1,n+1):
	if branch[i] != []:
		compare[i] = 1

arrival = [0 for i in range(n+1)]
ans = []
q = []

ind = 1
while arrival != compare:
	counter = base
	while not(arrival[ind] == 0 and compare[ind] == 1):
		ind += 1
	q.append(ind)
	arrival[ind] = 1
	section = [q[0]]
	while len(q) > 0:
		next = branch[q[0]]
		for i in range(len(next)):
			if arrival[next[i]] == 0:
				section.append(next[i])
				arrival[next[i]] = 1
				q.append(next[i])
		q.pop(0)
	psec = []
	for i in range(len(section)):
		psec.append(p[section[i]-1])
	t = section + psec + basemap
	search = collections.Counter(t)
	for i in search:
		if search[i] == 2:
			 counter += 1
	ans.append(counter)
print(max(ans))