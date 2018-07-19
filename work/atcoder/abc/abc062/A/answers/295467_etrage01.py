import sys

group = [[1,3,5,7,8,10,12], [4,6,9,11]]

xy = list(map(int, input().split()))
x = xy[0]
y = xy[1]

if x == 2 or y == 2:
    print("No")
    sys.exit(0)
else:
    for g in group:
        if x in g and y in g:
            print("Yes")
            sys.exit(0)
    print("No")