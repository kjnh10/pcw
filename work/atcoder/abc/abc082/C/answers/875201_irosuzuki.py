import sys

line = sys.stdin.readline().strip()
N = int(line)

line = sys.stdin.readline().strip()
a = [int(x) for x in line.split()]

xs = {}
for i in a:
    xs[i] = xs.get(i, 0) + 1

r = 0
for k in xs:
    if xs[k] < k:
        r += xs[k]
    elif xs[k] > k:
        r += xs[k] - k

print(r)
