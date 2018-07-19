import sys
from bisect import bisect_left
readline = sys.stdin.readline
N = int(input())
a = sorted(sorted(tuple((x-r, x+r) for _ in [0]*N for x, r in ((map(int, readline().split())),)), key=lambda x: x[1], reverse=True), key=lambda x: x[0], reverse=True)
inf = float("inf")
dp = [inf]*N

for l, r in a:
    i = bisect_left(dp, r)
    dp[i] = r

for i in range(N-1, -1, -1):
    if dp[i] != inf:
        print(i+1)
        break