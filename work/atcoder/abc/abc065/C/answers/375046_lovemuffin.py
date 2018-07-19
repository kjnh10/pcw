N ,M = map(int,input().split())
maxx = max(N,M)
minn = min(N,M)
if (maxx-minn)>1:
    print(0)
else:
    import math
    if maxx-minn == 1:
        n = 1
    else:
        n = 2
    print(n*math.factorial(N)*math.factorial(M)%(10**9+7))