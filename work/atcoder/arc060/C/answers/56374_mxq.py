import collections

N, A = [int(s) for s in input().split()]

x = [int(s) for s in input().split()]

S = [collections.Counter() for _ in range(51)]

S[0][0] = 1
for i, xi in enumerate(x):
    prev = [(k,s,c) for k in range(i+1) for s,c in S[k].items()]
    for (k,s,c) in prev:
        S[k+1][s+xi] += c
    #print(sum(sum(S[k].values()) for k in range(i+1)))

ans = 0
for (k, s, c) in ((k,s,c) for k in range(1,N+1) for s,c in S[k].items()):
    if A*k == s:
        ans += c

print(ans)