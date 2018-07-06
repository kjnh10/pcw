def read_ints():
    return [int(i) for i in input().split(" ")]

n, q = read_ints()
a = [0 for i in range(n)]
for i in range(q):
    l, r, t = read_ints()
    l -= 1
    r -= 1
    for j in range(l, r+1):
        a[j] = t

for i in a:
    print(i)
