import math
q = int(input())
a = [[int(i) for i in input().split()] for i in range(q)]
for i in a:
	if i[0]==i[1]: print((i[0]-1)*2)
	else:
		x = int(math.sqrt(i[0]*i[1]))
		if x*(x+1)<i[0]*i[1]: print(2*x-1)
		elif x==math.sqrt(i[0]*i[1]): print(2*x-3)
		else: print(2*x-2)