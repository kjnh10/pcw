N,R = map(int,input().split())
S = list(input())

walk = 0
for i in range(N - 1, -1, -1):
	if S[i] == '.':
		walk = max(i - R + 1, 0)
		break

shot = 0
for i in range(N - 1, -1, -1):
	if S[i] == '.':
		for j in range(max(i - R + 1, 0), i + 1):
			S[j] = 'o'
		shot += 1

res = walk + shot
print(res)