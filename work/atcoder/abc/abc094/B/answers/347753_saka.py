n,m,x = map(int,input().split())
a = list(map(int,input().split()))
counter = 0
for i in range(m):
	if a[i] < x:
		counter += 1
if counter >= (m-counter):
	print(m-counter)
else:
	print(counter)