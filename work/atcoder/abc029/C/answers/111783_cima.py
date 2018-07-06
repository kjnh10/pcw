import itertools
[print(*x,sep='') for x in itertools.product('abc',repeat=int(input()))]
