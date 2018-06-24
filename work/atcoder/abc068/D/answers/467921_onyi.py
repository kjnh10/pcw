# encoding:utf-8
 
def main():
	k = int(input())
	n = 50
	div = k // n
	res = k % n
 
	temp = [i for i in range(n)]
	temp = [temp[i] + (i >= (50 - res)) + div for i in range(n)]
 
	out = [str(x) for x in temp]
	print(n)
	print(" ".join(out))
 
	#print(calc(temp))
 
def calc(temp):
	i = 0
	while len([x for x in temp if x >= len(temp)]) > 0:
		temp = query(temp)
		#print([x for x in temp if x >= len(temp)])
		i += 1
	return i
 
def query(temp):
	temp.sort()
	temp = [x + 1 for x in temp]
	temp[-1] = temp[-1] - 1 - len(temp)
	return temp
 
if __name__ == '__main__':
	main()