import math
for i in range(int(input()), -1, -1):
	temp = math.sqrt(i)
	
	if math.floor(temp) == temp:
		print(i)
		break