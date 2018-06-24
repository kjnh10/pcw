X, A, B = [int(x) for x in input().split()]
if A - B >= 0:
	print("delicious")
elif X + A - B >= 0:
	print("safe")
else:
	print("dangerous")

