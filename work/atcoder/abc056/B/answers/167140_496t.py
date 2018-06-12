W,a,b = map(int,input().split())
c = abs(b - a) - W
if c < 0:
	c = 0

print(c)