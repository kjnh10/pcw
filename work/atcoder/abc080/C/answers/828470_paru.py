n = int(input())
f = []
for _ in range(n):
    f_ = list(map(int, input().split()))
    f.append(f_)

p = []
for _ in range(n):
    p.append(list(map(int, input().split())))


def help(a):
    if sum(a) == 0:
        return -float("inf")
    res = 0
    for i in range(n):
        num = 0
        for j in range(10):
            if a[j] == 1 and f[i][j] == 1:
                num += 1
        res += p[i][num]
    return res
lst = []
for a1 in range(2):
        for a2 in range(2):
            for a3 in range(2):
                for a4 in range(2):
                    for a5 in range(2):
                        for a6 in range(2):
                            for a7 in range(2):
                                for a8 in range(2):
                                    for a9 in range(2):
                                        for a10 in range(2):
                                            res = help([a1, a2, a3, a4, a5, a6, a7, a8, a9, a10])
                                            lst.append(res)
print(max(lst))