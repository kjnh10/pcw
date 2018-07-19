N, W = map(int, input().split())
item = []
for i in range(N):
    item.append([int(s) for s in input().split()])
hoge = item[0][0]
item = [[w-hoge, v] for w, v in item]
item = [0]+item

dp = [[-1] * (N*3+1+400*N) for i in range(N+1)]
dp[0][0] = 0

for i in range(1, N+1):
    for j in range(len(dp[0])):
        if dp[i-1][j] == -1:
            continue
        p_worth = dp[i-1][j]
        p_weight = j%400
        count = j//400
        c_worth = dp[i][j]
        n_worth = item[i][1]
        item_weight = item[i][0]
        new_weight = p_weight + count*hoge + item_weight + hoge
 
        if new_weight <= W:
            dp[i][j+400+item_weight] = max(c_worth, p_worth + n_worth)
        dp[i][j] = max(p_worth, c_worth)
print(max(dp[N]))