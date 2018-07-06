N,K = map(int, input().split())
data = list(map(int, input().split()))
res = []
ans = 0
tmp_sum = 0
for val in data:
    res.append(val)
    tmp_sum += val
    if (len(res) == K):
        ans += tmp_sum
        tmp_sum -= res[0]
        res.pop(0)
print (ans)        
        
