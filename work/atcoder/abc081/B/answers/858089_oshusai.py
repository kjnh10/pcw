n = int(input())
a = list(map(int, input().split()))

ans = float("inf")
for i in range(n):
    if(a[i] % 2 == 1):
        ans = 0
        break
    else:
        tmp = a[i]
        count = 0
        while(tmp % 2 == 0):
            tmp /= 2
            count += 1
        if(count < ans):
            ans = count
print(ans)