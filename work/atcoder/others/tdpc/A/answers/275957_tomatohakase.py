num = int(input())
points = (int(n) for n in input().split(" "))
dp = [0 for n in range(100 * num + 1)]
dp[0] += 1
for p in points:
    temp = dp[:]
    temp[p] = 1
    for i in range(len(dp)):
        if dp[i] and p + i < len(dp):
            temp[p + i] = 1
    dp = temp
answer = 0
for d in dp:
    answer += d
print(answer)
