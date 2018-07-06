def circular_list(L, start = None):
  if start is not None:
    start %= len(L)
    for l in L[start:]:
      yield l
  while True:
    for l in L:
      yield l

def interval_sum(l, interval_length):
  s = sum(a for a,_ in zip(circular_list(l, -interval_length), range(interval_length)))
  for a,b in zip(l,circular_list(l, -interval_length)):
    s += a
    s -= b
    yield s

MOD = 10**9+7

D = int(input())

N = input()


dp = [(1,)+(0,)*(D-1)]

for _ in range(len(N)-1):
  dp.append(tuple(a%MOD for a in interval_sum(dp[-1], 10)))

cnt = 0
s = 0
for n,d in zip(N,reversed(dp)):
  n = int(n)
  s %= D
  cnt += sum(d[(s-i)%D] for i in range(n))%MOD
  cnt %= MOD
  s -= n

print(cnt-1)