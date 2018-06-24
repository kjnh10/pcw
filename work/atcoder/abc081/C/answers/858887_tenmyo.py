import collections
n, k = map(int, input().split())
a = list(map(int, input().split()))
d = collections.defaultdict(int)

for e in a:
    d[e] += 1

cnts = sorted(d.values())
print(sum(cnts[:-k]))
