n = int(input())
plan = [list(map(int,input().split())) for i in range(n)]
t = x = y = 0
for i in plan:
    if (i[0] - t) >= (abs(x-i[1]) + abs(y-i[2])) and (i[0] - t) % 2 == (abs(x-i[1]) + abs(y-i[2])) % 2:
        t = i[0]
        x = i[1]
        y = i[2]
    else:
        print("No")
        break
else:
    print("Yes")
