MOD = 10**9 + 7
fact = [0] * (10**5 + 1)
fact[0] = 0
fact[1] = 1
for i in range(2,10**5 + 1):
	fact[i] = (i * fact[i-1]) % MOD

N = int(input())
T = [0]*N
cnt = {}
for i in range(N):
	T[i] = int(input())

	if T[i] not in cnt:
		cnt[T[i]] = 1
	else:
		cnt[T[i]] += 1

T = sorted(T)
cum_sum = [0] * N
cum_sum[0] = T[0]
for i in range(1,N):
	cum_sum[i] = cum_sum[i-1] + T[i]
total = sum(cum_sum)

res = 1
for key,value in cnt.items():
	res = (res * fact[value]) % MOD

print(total)
print(res)