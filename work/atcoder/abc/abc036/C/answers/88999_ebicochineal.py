n = int(input())
a = [int(input()) for x in range(n)]
s = sorted(set(a))
d = {y : x for x, y in enumerate(s)}
for i in a:
    print(d[i])