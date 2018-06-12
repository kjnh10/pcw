

N = int(input())
A = list(map(int, input().split()))

res = 1<<30
cand = -100
while cand <= 100:
    tmp = 0
    for a in A:
        dif = cand - a
        tmp += dif*dif
    res = min(res, tmp)


    cand += 1

print(res)