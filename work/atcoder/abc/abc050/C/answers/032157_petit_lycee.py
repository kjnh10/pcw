from collections import Counter

N = int(input())
A = list(map(int, input().split()))
res = (2 ** (N // 2)) % (10 ** 9 + 7)
c = Counter()
for i in A:
    c[i] += 1

s = 2 if N % 2 else 1
for i in range(s, N, 2):
    if c[i] != 2:
        res = 0
        break

if s == 2 and c[0] != 1:
    res = 0
print(res)
