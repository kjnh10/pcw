d = 2025 - int(input())
for i in range(1, 10):
    if d%i==0 and d//i < 10:
        print("%d x %d" % (i, d//i))