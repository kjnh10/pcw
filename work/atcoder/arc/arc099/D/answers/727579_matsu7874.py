def calc(n):
    if n == 0:
        return -1
    s = 0
    n_ = n
    while n:
        s += n%10
        n //= 10
    return n_/s

# res = []
# for i in range(1,10**6):
#     res.append((i/sunuke(i), i))
#     # print(i, i/sunuke(i))
# res.sort()
# max_i = 0
# ret = []
# for v, i in res:
#     if i > max_i:
#         max_i = i
#         print(i, v)
#         ret.append(i)
# print(ret)

k = int(input())
for i in range(1, min(9,k)+1):
    print(i)
cnt = min(9,k)
i = min(9,k)
d = 1

while cnt < k:
    # print(i,d)
    while calc(i+d) > calc(i+d*10):
        d *= 10
    i +=d
    print(i)
    cnt += 1

# vv = [30999,39999]
# for v in vv:
#     print(v, v/sunuke(v), 10)