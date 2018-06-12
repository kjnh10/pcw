n = int(input())
a = list(map(int,input().split()))

lis = [pow(-1,i) for i in range(n)]

res1 = 0
s1 = 0
for i in range(n):
	s1 += a[i]
	if lis[i] == 1:
		if s1 <= 0:
			res1 += 1 - s1
			s1 = 1
	else:
		if s1 >= 0:
			res1 += s1 + 1
			s1 = -1

lis = [pow(-1,i)*(-1) for i in range(n)]

res2 = 0
s2 = 0
for i in range(n):
	s2 += a[i]
	if lis[i] == 1:
		if s2 <= 0:
			res2 += 1 - s2
			s2 = 1
	else:
		if s2 >= 0:
			res2 += s2 + 1
			s2 = -1

print(min(res1,res2))