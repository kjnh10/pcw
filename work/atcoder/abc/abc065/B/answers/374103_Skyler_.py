N = int(input())
a = list()
for i in range(N):
	a.append(int(input()))

temp = 1
count = 0
while temp != 2 and count <= 100001:
	temp = a[temp - 1]
	count += 1

if count > 100000:
	print(-1)
else:
	print(count)