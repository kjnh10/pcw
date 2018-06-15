N = int(input())
isopen = [list(map(int,input().split())) for i in range(N)]
gain = [list(map(int,input().split())) for i in range(N)]

ans = -float('inf')
for i in range(1,2**10):
    tmp = 0
    for n in range(N):
        c = 0
        for b in range(10):
            if ((i >> b)&1) & isopen[n][b]:
                c += 1
        tmp += gain[n][c]
    ans = max(ans, tmp)
print(ans)
