n, q = map(int, input().split())
a = [0] * n
for i in range(q):
    l, r, t = map(int, input().split())
    l -= 1
    for j in range(l, r):
        a[j] = t
for x in a:
    print(x)
