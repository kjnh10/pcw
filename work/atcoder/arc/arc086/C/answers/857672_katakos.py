from collections import Counter
from operator import itemgetter

n, k = map(int, input().split())
a = Counter(map(int, input().split()))
sa = sorted(a.items(), key=itemgetter(1), reverse=True)

if len(sa) <= k:
    print(0)
else:
    print(sum(c for m, c in sa[k:]))
