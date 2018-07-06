n=int(input())
ans=n
aw,ah=1,1
for w in range(1,n+1):
    h = int(n/w)
    if ans > (n-w*h) + abs(w-h):
        ans = (n-w*h) + abs(w-h)
        aw=w
        ah=h
print(ans)
