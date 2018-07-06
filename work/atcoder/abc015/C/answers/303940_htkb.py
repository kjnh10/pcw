N, K = map(int, input().split())
t = [[int(s) for s in input().split()] for i in range(N)]

q = [(n, 1) for n in t[0]]
flag = True
while q:
    n, i = q.pop()
    if n==0:
        flag = False
        break
    elif i < N:
        for _n in t[i]:
            q.append((n^_n, i+1))
print("Nothing" if flag else "Found")