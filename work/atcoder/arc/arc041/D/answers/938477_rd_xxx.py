H,W = map(int,input().split())
src = [list(map(int,input())) for i in range(H)]
ans = [[0 for j in range(W)] for i in range(H)]

for i in range(1,H-1):
    for j in range(1,W-1):
        mn = min(src[i-1][j], src[i][j-1], src[i+1][j], src[i][j+1])
        if mn == 0: continue
        ans[i][j] += mn
        src[i-1][j] -= mn
        src[i][j-1] -= mn
        src[i+1][j] -= mn
        src[i][j+1] -= mn

for row in ans:
    print(''.join(list(map(str,row))))
