X,A,B = map(int,input().split())

if A-B>=0:
    print("delicious")
else:
    if X+A-B>=0:
        print("safe")
    else:
        print("dangerous")