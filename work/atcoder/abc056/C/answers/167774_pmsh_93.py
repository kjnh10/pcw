X = int(input().strip())
 
t = 0
x = 0
if X == 0:
	print(0)
else:
	while(True):
		t += 1
		x += t
		if x >= X:
			print(t)
			break