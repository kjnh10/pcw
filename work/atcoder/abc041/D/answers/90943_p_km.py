import collections

memo = {0: 1}
def dp(s):
    if s not in memo:
        ans = 0
        for i in range(1, n + 1):
            if s & 1 << i:
                if not follow[i] & s:
                    ans += dp(s ^ 1 << i)
        memo[s] = ans

    return memo[s]

n, m = [int(x) for x in input().split()]
follow = collections.defaultdict(int)
for _ in range(m):
    x, y = [int(x) for x in input().split()]
    follow[x] |= 1 << y

print(dp(((1 << n) - 1) << 1))
