n,l = map(int, input().split())
s = list(input())

cnt = 1
res = 0
for e in s:
	if e == "+":
		cnt += 1
		if cnt > l:
			res += 1
			cnt = 1
	else:
		cnt -= 1

print(res)
