N,C = map(int,input().split())
ps = [[] for i in range(C)]
for i in range(N):
    s,t,c = map(int,input().split())
    ps[c-1].append((s,t))

MAX_N = 10**5+3
imos = [0] * MAX_N
for c in range(C):
    ps[c].sort()
    cont = False
    for i,(s,t) in enumerate(ps[c]):
        if not cont:
            imos[s-1] += 1
        if i < len(ps[c])-1 and t == ps[c][i+1][0]:
            cont = True
        else:
            imos[t] -= 1
            cont = False

ans = t = 0
for a in imos:
    t += a
    ans = max(ans, t)
print(ans)
