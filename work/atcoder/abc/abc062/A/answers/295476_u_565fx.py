L1 = [1, 3, 5, 7, 8, 10, 12]
L2 = [4, 6, 9, 11]
L3 = [2]
x, y = list(map(int, input().split()))

X = 0
Y = 0
if L1.count(x) == 1:
	X = 1
elif L2.count(x) == 1:
	X = 2
else:
	X = 3

if L1.count(y) == 1:
	Y = 1
elif L2.count(y) == 1:
	Y = 2
else:
	Y = 3

if X == Y:
	print("Yes")
else:
	print("No")