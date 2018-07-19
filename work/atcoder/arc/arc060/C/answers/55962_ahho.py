N, A = map(int, input().split(' '))

X = map(int, input().split(' '))
X = [x - A for x in X]

from collections import defaultdict
counter = defaultdict(int)
counter[0] = 1

for x in X:
	copy = dict(counter)
	for d,c in copy.items():
		counter[d+x] += c

print(counter[0]-1)