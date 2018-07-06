n = int(input())
ans = 1000000000
for k in range(1,n+1):
    ans = min(ans,n-k*(n//k)+abs(k-(n//k)))

print(ans)