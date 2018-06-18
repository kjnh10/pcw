S = input()
N = len(S)
for i in range(N):
	if S[i]=="A":
		a_n = i
		break
for i in range(N-1, -1, -1):
	if S[i]=="Z":
		z_n = i
		break
print(z_n-a_n+1)
