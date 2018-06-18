n = int(input())
lis = list(map(int,input().split()))
a = max(lis)
lis.remove(a)
ans = 100000000000
for i in range(n-1):
	if abs(a/2 - lis[i]) < ans:
		ans = abs(a/2 - lis[i])
		an = lis[i]
print(a,an)