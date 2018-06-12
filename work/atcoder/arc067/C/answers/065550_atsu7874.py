import collections

MOD = (10 ** 9 + 7)

n = int(input())
p = [True for i in range(n+1)]
p[0] = False
p[1] = False
pf = collections.defaultdict(int)
for i in range(2, n+1):
    if not p[i]:
        continue
    j = i * i
    while j <= n:
        p[j] = False
        j += i
    cnt = 1
    v = i
    while v <= n:
        cnt += n//v
        v *= i
    pf[i] = cnt
total = 1
for v in pf.values():
    total = (total * v) % MOD

print(total)