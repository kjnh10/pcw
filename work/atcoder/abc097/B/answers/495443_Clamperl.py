x = int(input())
c = [1]
for i in range(2,32):
	num = 2
	while i**num<=x:
		c.append(i**num)
		num+=1
print(max(c))