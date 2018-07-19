from math import sqrt,log10,floor

INF = 10 ** 10

n = int(input())

ans = INF
for i in range(1,floor(sqrt(n))+1):
    if n % i == 0:
        ans = min(ans,floor(log10(max(i,n//i)))+1)
print(ans)