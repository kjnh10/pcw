A,B= list(map(int,input().split()))


if (A+B)%3==0 or A%3==0 or B%3==0:
    print("Possible")
else:
    print("Impossible")