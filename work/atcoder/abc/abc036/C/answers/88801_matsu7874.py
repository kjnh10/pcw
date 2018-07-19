n = int(input())
a = [int(input()) for i in range(n)]
b = list(set(a))
b.sort()
c = dict()
for i in range(len(b)):
    c.update({b[i]:i})
for i in range(n):
    print(c[a[i]])
