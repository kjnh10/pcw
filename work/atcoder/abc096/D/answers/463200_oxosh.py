# D
# find primes s.t. p == 1(mod 5)
N = int(input())

primes = [1]*55555
primes[0] = 0
primes[1] = 0

for i in range(250):
    if primes[i] == 1:
        for j in range(2*i, 55555, i):
            primes[j] = 0

res_list = []
for i in range(55555):
    if primes[i] == 1 and i % 5 == 1:
        res_list.append(str(i))
    if len(res_list) == N:
        break
print(" ".join(res_list))