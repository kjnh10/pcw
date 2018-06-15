import sys
inp = lambda t: t(sys.stdin.readline().strip())
inpm = lambda t: map(t, sys.stdin.readline().split())
inpl = lambda t: list(map(t, sys.stdin.readline().split()))
print = lambda x, end='\n': sys.stdout.write(str(x) + end)

x, a, b = inpm(int)
if abs(a - x) < abs(b - x):
	print('A')
else:
	print('B')