n = int(input())
S = [list(input()) for i in range(n)]
s1 = S.pop(0)
A = []
for s in s1:
	flag = 0
	for t in S:
		if s not in t:
			flag = 1
	if flag == 0:
		A.append(s)
		for i in range(len(S)):
			S[i].remove(s)
A.sort()
print("".join(A))