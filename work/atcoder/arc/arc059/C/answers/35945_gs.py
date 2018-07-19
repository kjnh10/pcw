N = int(input())
a = list(map(int, input().split()))

m = sum(a)//N

ans1 = 0
ans2 = 0
ans3 = 0
for k in range(N):
    ans1 += (a[k]-m)**2
    ans2 += (a[k]-m-1)**2
    ans3 += (a[k]-m+1)**2

print(min(ans1,ans2,ans3))