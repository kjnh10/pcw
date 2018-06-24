N, T = map(int, input().split())
tn = map(int, input().split())

prev = 0
ans = 0
for t in tn:
    ans += min(T, t - prev + T)
    prev = t + T
    
print(ans)