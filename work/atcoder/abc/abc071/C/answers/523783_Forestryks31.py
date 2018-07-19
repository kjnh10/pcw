import sys
inp = lambda t: t(sys.stdin.readline().strip())
inpm = lambda t: map(t, sys.stdin.readline().split())
inpl = lambda t: list(map(t, sys.stdin.readline().split()))

n = inp(int)
l = inpl(int)

s = set()

a = 0
b = 0

for i in l:
	if i in s:
		if i > a and a < b:
			a = i
		elif i > b:
			b = i
		s.remove(i)
	else:
		s.add(i)

print(a * b)