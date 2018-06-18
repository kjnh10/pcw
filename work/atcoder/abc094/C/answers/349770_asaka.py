import copy
n = int(input())
x = list(map(int,input().split()))
a = copy.copy(x)
a.sort()
half = n//2
for i in range(n):
	if x[i] < a[half]:
		print(a[half])
	elif x[i] == a[half]:
		print(a[half-1])
	else:
		print(a[half-1])