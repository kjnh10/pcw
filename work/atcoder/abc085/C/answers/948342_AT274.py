N, Y = map(int, input().split())
flg = False
for x in range(N+1):
    for y in range(N+1):
        if ((10000*x + 5000*y + (N-x-y)*1000)==Y) & (x+y<=N):
            print(x,y,(N-x-y))
            flg = True
            break
    if flg:
        break
else:
    print(-1,-1,-1)

