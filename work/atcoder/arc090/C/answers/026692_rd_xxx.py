N = int(input())
src = [list(map(int,input().split())) for i in range(2)]

ans = 0
for i in range(N):
    tmp = sum(src[0][:i+1]) + sum(src[1][i:])
    ans = max(tmp,ans)
print(ans)
