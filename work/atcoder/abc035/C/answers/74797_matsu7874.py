n, q = map(int, input().split())
a = [0 for i in range(200001)]
for i in range(q):
    l, r = map(int, input().split())
    a[l - 1] += 1
    a[r] -= 1
b = [0 for i in range(200001)]
b[0] = a[0] % 2
for i in range(1, n):
    b[i] = (b[i - 1] + a[i]) % 2
print(''.join([str(b[i]) for i in range(n)]))
