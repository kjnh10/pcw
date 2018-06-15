# My code doesnt work, I have no idea why
# My code works, I have no idea why
n = str(input())
s = 0
for i in range(len(n)):
	s += int(n[i])
print("Yes" if int(n)%s==0 else "No")