n, m = map(int, input().split())

abmap = {}
for a, b in [map(int, input().split()) for x in range(m)]:
    if abmap.get(a) == None:
        abmap[a] = []
    abmap[a].append(b)

    if abmap.get(b) == None:
        abmap[b] = []
    abmap[b].append(a)

print("\n".join(map(str, [len(list(filter(lambda x: x is not first and x not in abmap[first], set(__import__("itertools").chain(*[abmap[friend] for friend in abmap[first]]))))) if abmap.get(first) != None else 0 for first in range(1, n + 1)])))
