N,M = map(int,input().split())
fast = N-M
print((fast*100 + M*1900) * (2**M))