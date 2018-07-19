n = int(input())
a = list(map(int, input().split()))

if n % 2 == 0:
	b = a[1::2]
	c = a[0::2]
	b.reverse()
	b.extend(c)
else:
	b = a[0::2]
	c = a[1::2]
	b.reverse()
	b.extend(c)

b = [str(i) for i in b]
b = ' '.join(b)
print(b)
