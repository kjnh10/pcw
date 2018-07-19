N = int(input())
a = [int(input()) for x in range(N)]

count = 1
flag = False
place = 1
for i in range(N):
    place = a[place-1]
    if place == 2:
        flag = True
        print(count)
        break
    else:
        count +=1
if flag == False:
    print(-1)