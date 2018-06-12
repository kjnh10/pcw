from collections import Counter
n = int(input())
C = Counter(map(int, input().split()))
opt = -1
for x in C:
    opt = max(opt, C[x-1]+C[x]+C[x+1])
print(opt)