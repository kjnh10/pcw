from itertools import accumulate

n = int(input())
a1 = list(accumulate(map(int, input().split())))
a2 = list(accumulate(map(int, input().split())))
s2 = a2[-1]
ans = a1[0]
for i in range(1, n):
    ans = max(ans, a1[i] - a2[i - 1])
print(ans + s2)
