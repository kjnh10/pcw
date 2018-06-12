N, C = map(int, input().split())

su = [0]*(10**5+1)
Q = [[] for i in range(C)]
for i in range(N):
    s, t, c = map(int, input().split())
    Q[c-1].append([s, t])
R = [[] for i in range(C)]
for i in range(C):
    q = Q[i]; q.sort()
    r = R[i]
    if len(q) == 0:
        continue
    r.append(q[0])
    for j in range(1, len(q)):
        if r[-1][1] == q[j][0]:
            r[-1][1] = q[j][1]
        else:
            r.append(q[j])
    for a, b in r:
        su[a-1] += 1
        su[b] -= 1
ans = 0; tmp = 0
for i in range(10**5+1):
    tmp += su[i]
    ans = max(ans, tmp)
print(ans)

