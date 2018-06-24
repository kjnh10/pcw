n = int(input())
s = input()
a = s
f = 0
for c in a:
	if c=="(":
		f+=1
	else:
		if f>0:
			f-=1
		else:
			s = "(" + s
for i in range(f):
	s = s + ")"

print(s)
