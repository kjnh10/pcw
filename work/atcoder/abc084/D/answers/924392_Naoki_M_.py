sz = int(1e5)
isprime = [True for _ in range(sz + 1)]

for i in range(sz + 1):
    if i <= 1:
        isprime[i] = False
    elif isprime[i]:
        j = 2 * i
        while j <= sz:
            isprime[j] = False
            j += i

cnt = [0 for _ in range(sz + 1)]
for i in range(3, sz + 1):
    if i % 2 == 1 and isprime[i] and isprime[(i + 1) // 2]:
        cnt[i] = cnt[i - 1] + 1
    else:
        cnt[i] = cnt[i - 1]

q = int(input())
for _ in range(q):
    l, r = map(int, input().split())
    print(cnt[r] - cnt[l - 1])