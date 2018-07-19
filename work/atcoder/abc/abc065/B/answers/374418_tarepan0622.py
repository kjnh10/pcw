n = int(input())
a = [0] + [int(input()) for i in range(n)]

end = {}

end[1] = True
to = a[1]

cnt = 0
while True:
    cnt += 1
    if to == 2:
        print(cnt)
        __import__("sys").exit()
    if end.get(to) == None:
        end[to] = True
        to = a[to]
    else:
        break

print(-1)
