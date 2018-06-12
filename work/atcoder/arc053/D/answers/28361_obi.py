# def makelist(n, m):
# 	return [[0 for i in range(m)] for j in range(n)]

s = input()

alph = [0]*26

for c in s:
	alph[ord(c) - ord('a')] += 1

one = 0
two = 0

for e in alph:
	two += e // 2
	one += e % 2

if one == 0:
	print(two * 2)
else:
	tmp = two // one
	print(tmp*2 + 1)
