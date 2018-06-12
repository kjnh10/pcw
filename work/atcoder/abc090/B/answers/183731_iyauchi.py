n, m = map(int, input().split())
res = 0
for i in range(n, m+1):
    if str(i) == str(i)[::-1]:
        res += 1
print(res)