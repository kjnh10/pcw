import sys
stdin = sys.stdin
def na(): return map(int, stdin.readline().split())
def ns(): return stdin.readline().strip()

n,m = na()

rule = [0]*n
for i in range(m):
    x,y = na()
    rule[y-1] |= 1<<x-1

u = 1<<n
dp = [0]*u
dp[0] = 1
for i in range(u):
    for j in range(n):
        if i>>j&1:
            k = i^1<<j
            if (rule[j]&k) == rule[j]:
                dp[i] += dp[k]
print(dp[u-1])
