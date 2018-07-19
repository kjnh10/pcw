# coding: utf-8
nums = [int(x) for x in input().split()]
N,M = nums[0],nums[1]
imos = [0 for i in range(100003)]
V = 0
for i in range(N):
    nums = [int(x) for x in input().split()]
    a,b,v = nums[0],nums[1],nums[2]
    V += v
    imos[a] += v
    imos[b+1] -= v

ans = []
j = 0
for i in imos:
    ans.append(j+i)
    j += i
print(V-min(ans[1:M+1]))