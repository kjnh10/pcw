# C
N, T = map(int, input().split())
tv = list(map(int, input().split()))

res = 0

for i in range(len(tv)-1):
    if tv[i+1] - tv[i] < T:
        res += tv[i+1] - tv[i]
    else:
        res += T
res += T

print(res)