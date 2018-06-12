# -*- coding: utf-8 -*-
from collections import Counter
def inpl(): return tuple(map(int, input().split()))

N, K = inpl()
A = inpl()
C = Counter(A)

print(sum(sorted(C.values(), reverse=True)[K:]))