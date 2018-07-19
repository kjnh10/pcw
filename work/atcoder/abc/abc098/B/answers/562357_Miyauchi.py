n = int(input())
s = input()

res = 0
for i in range(n):
    tmp_res = 0
    tmp1 = set(s[:i])
    tmp2 = set(s[i:])
    for j in tmp2:
        if j in tmp1:
            tmp_res += 1
    if tmp_res > res:
        res = tmp_res
print(res)