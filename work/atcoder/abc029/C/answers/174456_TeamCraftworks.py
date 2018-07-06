from itertools import product as prod

n = int(input())

for s in prod(('','a','b','c'),repeat=n):
    ans = "".join(s)
    if len(ans) == n:
        print(ans)
