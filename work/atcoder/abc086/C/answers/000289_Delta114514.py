n = int(input())
pretime, prex, prey = 0, 0, 0
for i in range(n):
    nowtime, nowx, nowy = map(int, input().split())
    time = nowtime - pretime
    x = abs(nowx - prex)
    y = abs(nowy - prey)
    if x+y > time:
        print("No")
        exit()
    if (x+y) % 2 != time % 2:
        print("No")
        exit()
    pretime = nowtime
    prex, prey = nowx, nowy
else:
    print("Yes")