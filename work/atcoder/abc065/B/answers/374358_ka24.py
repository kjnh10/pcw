n = int(input())
a = [int(input()) for i in range(n)]
memo = [0 for i in range(n+1)]

ind = 0
cnt = 0
while 1:
    nex = a[ind]
    cnt += 1
    if nex == 2:
        print(cnt)
        break
    if memo[nex] == 1:
        print(-1)
        break
    memo[nex] = 1
    ind = nex-1