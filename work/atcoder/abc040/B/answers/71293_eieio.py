n = int(input())
ans = 10 ** 6
if n == 1:
    ans = 0
else:
    for i in range(1,int(n**1/2)+1):
        if n % i + abs(i - n // i) < ans:
            ans = n % i + abs(i - n // i)
print(ans)