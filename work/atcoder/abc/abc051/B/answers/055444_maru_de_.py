K, S = map(int, input().split())
count = 0
x_min = max(0, S-K*2)
x_max = min(K, S)
for x in range(x_min, x_max+1):
	rest = S-x
	if rest<K:
		count = count+rest+1
	else:
		count = count+K*2-rest+1
print(count)