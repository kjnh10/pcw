n = int(input())
a = list(map(int,input().split()))

dp1 = [0]*(n-1)
dp2 = [0]*(n-1)
dp1[0]= a[0]
dp2[0]= sum(a[1:])
m = abs(dp1[0]-dp2[0])


for i in range(1,n-1):
    dp1[i] = dp1[i-1]+a[i]
    dp2[i] = dp2[i-1]-a[i]
    tm = abs(dp1[i]-dp2[i])
    if tm < m:
        m = tm

print(m)