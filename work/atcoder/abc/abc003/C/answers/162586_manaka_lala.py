N, K = map(int, input().split())
R = [int(i) for i in input().split()]
R = sorted(R, reverse=True)
R = R[:K]
    
ans = 0
for i in range(1, K+1):
    ans = (ans + R[-i]) / 2

print(ans)
