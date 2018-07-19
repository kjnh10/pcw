N,A,B = list(map(int,input().split()))
l=list(map(int,input().split()))

c=0
for i in range(len(l)-1):
	if (l[i+1]-l[i])*A<B:
		c+=(l[i+1]-l[i])*A
	else:
		c+=B

print(c)
