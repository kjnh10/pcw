def combination(n, r):
    res = 1
    t = r - 1
    while t >= 0:
        res = res * (n - t) // (r - t)
        t -= 1
    return res

n,a,b = map(int, input().split())
v = list(map(int, input().split()))

v.sort()
v.reverse()

t = 0
for i in range(a):
    t += v[i]
t /= a
print(t)

cnt = 0
if v[0] == v[a-1]:
    candidate = 0
    cnt = 0
    for i in range(n):
        if v[i] == v[0]:
            candidate += 1
        else:
            break
    for i in range(a, min(b, candidate)+1):
        cnt += combination(candidate, i)
else:
    cnt = 0
    first = 50
    last = 0
    for i in range(n):
        if v[i] == v[a-1]:
            first = min(i, first)
            last = max(i, last)
    candidate = last - first + 1
    cnt += combination(candidate, a-first)
print(cnt)
