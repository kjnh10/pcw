N = int(input().strip())
power = 1
MOD = 1000000007
for i in range(1, N+1):
	power = (power * i) % MOD
 
print(power)