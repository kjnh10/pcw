n, m, x = map(int, input().split())
a = map(int, input().split())

left = 0
right = 0

for ai in a:
	if ai < x:
		left += 1
	else:
		right += 1

print(min(left, right))
