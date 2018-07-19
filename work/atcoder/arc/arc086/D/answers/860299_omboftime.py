#全て正か負になるようにすればいい N
#あとは小さい方から足していくかするだけ
n = int(input())
a = list(map(int, input().split()))

ma = max(a)
mi = min(a)
flag = 0
#全部負
if ma <= 0:
    flag = 1
#全部正
elif mi >= 0:
    flag = 0
else:
    #全部負にする
    if abs(ma) < abs(mi):
        flag = 2
    #全部正にする
    else:
        flag = 3
cnt = 0
printer = ""
if flag == 2:
    x = a.index(mi)
    for i in range(n):
        if i == x:
            continue
        cnt += 1
        printer += "{0} {1}\n".format(x + 1, i + 1)
if flag == 3:
    x = a.index(ma)
    for i in range(n):
        if i == x:
            continue
        cnt += 1
        printer += "{0} {1}\n".format(x + 1, i + 1)
if flag == 0 or flag == 3:
    for i in range(n - 1):
        cnt += 1
        printer += "{0} {1}\n".format(i + 1, i + 2)
elif flag == 1 or flag == 2:
    for i in range(n-1):
        cnt += 1
        printer += "{0} {1}\n".format(n - i, n - i - 1)
print(cnt)
print(printer[:-1])
