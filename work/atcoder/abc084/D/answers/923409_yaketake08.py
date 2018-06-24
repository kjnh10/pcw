M = 10**6
p = [1]*M
p[0] = p[1] = 0
for i in range(2, 4*10**4):
    if p[i]:
        for j in range(i*i, M, i):
            p[j] = 0
C = [0]*M
for i in range(2, M):
    if p[i] and p[(i+1)//2]:
        C[i] = C[i-1] + 1
    else:
        C[i] = C[i-1]
q = int(input())
for i in range(q):
    l, r = map(int, input().split())
    print(C[r] - C[l-1])
