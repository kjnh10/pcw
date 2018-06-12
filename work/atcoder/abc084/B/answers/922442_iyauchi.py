a, b = map(int, input().split())
val = input().split("-")
if len(val) != 2:
    print("No")
else:
    if len(val[0]) == a and len(val[1]) == b:
        print("Yes")
    else:
        print("No")