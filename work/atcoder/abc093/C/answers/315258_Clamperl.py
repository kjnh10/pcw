a,b,c = (int(i) for i in input().split())
x,answer = [a,b,c],0
x.sort()
y = x[2]-x[1]
x[0] = x[0]+y
if (x[2]-x[0])%2==0:
	print(y+(x[2]-x[0])//2)
else:
	print(y+(x[2]-x[0]+3)//2)