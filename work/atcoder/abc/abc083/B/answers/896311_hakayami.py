out = 0
N, A, B = map(int,input().split())
for i in range(1,N+1):
    P = str(i)
    sum = 0
    for j in P:
        sum+=int(j)
    if A<=sum and sum<=B:
        out+=i
print(out)

