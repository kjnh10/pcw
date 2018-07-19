# -*- coding:utf-8 -*-
import itertools
N, M = map(int, input().split())
template = [ tmp for tmp in range(1,N+1) ]
a = [ int(input()) for _ in range(M) ]
writedFlag = {}
for tmp in itertools.chain(reversed(a), template):
    if tmp not in writedFlag:
        print(tmp)
        writedFlag[tmp] = 1