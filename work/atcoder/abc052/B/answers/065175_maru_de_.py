N = int(input())
S = input()

x = 0
max_x = 0
for s in S:
	if s=='I':
		x = x+1
	else:
		x = x-1
	max_x = max(x, max_x)
print(max_x)