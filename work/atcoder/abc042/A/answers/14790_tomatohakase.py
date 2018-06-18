cond = [int(n) for n in input().split(" ")]
five,seven = 0,0
for c in cond:
    if c == 5:
        five += 1
    elif c == 7:
        seven += 1
else:
    if five == 2 and seven == 1:
        print("YES")
    else:
        print("NO")