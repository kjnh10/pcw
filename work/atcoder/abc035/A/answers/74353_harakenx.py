w,h = map(int,input().split())

if (w/h)%(4/3) != 0:
    print("16:9")
else:
    print("4:3")