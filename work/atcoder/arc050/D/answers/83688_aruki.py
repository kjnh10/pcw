R,B=[int(x) for x in input().split()]
x,y=[int(x) for x in input().split()]

def f(D):
	low = (y*D-B+y-2)//(y-1)
	high = (R-D)//(x-1)
	if low<=high and high>=0 and low<=B and low*x<=R:
		return True
	else:
		return False

l = 0
r = 5000000000000000001
m=-1

while r-l>1:
	m=(l+r)//2
	if f(m):
		l = m
	else:
		r = m

print(l)