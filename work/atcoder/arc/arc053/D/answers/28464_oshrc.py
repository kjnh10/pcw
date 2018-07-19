import collections

count = collections.Counter()

for c in input():
    count[c] += 1

n_odd = 0
for c in count:
    if count[c] % 2 == 1:
        count[c] -= 1
        n_odd += 1

n = sum(count.values()) // 2
if n_odd == 0:
    print(n*2)
else:
    print(1 + (n//n_odd)*2)
