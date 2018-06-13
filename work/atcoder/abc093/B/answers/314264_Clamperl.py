a,b,k = (int(i) for i in input().split())
x,y = set(),[]
for i in range(a,min(b+1,a+k)):
	x.add(i)
for i in range(b,max(a-1,b-k),-1):
	x.add(i)
for i in x:
	y.append(i)
y.sort()
for i in y:
	print(i)