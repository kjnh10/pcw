n, Y = map(int, input().split())
Y //= 1000
for z in range(Y//10+1):
    for y in range((Y-z*10)//5+1):
        x = Y - z*10 - y*5
        if x < 0:
            break
        if x + y + z == n:
            print(z, y, x)
            exit(0)
print(-1, -1, -1)
