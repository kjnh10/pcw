from collections import Counter
MOD = 10**9 + 7

def factorial_mod(n):
	res = 1
	for i in range(2,n+1):
		res = (res * i) % MOD
	return res

N = int(input())
T = list(sorted([int(input()) for _ in range(N)]))

cum_sum = [0] * N
for i in range(N):
	if i == 0:
		cum_sum[i] = T[i]
	else:
		cum_sum[i] = T[i] + cum_sum[i-1]
penalty = sum(cum_sum)

cnt = Counter(T)
res = 1
for key, value in cnt.items():
	res = (res * factorial_mod(value)) % MOD

print(penalty)
print(res)