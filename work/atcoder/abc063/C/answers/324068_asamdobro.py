N = int(input())
S = sorted([int(input()) for i in range(N)])

tot = sum(S)
if tot % 10 != 0:
    print(tot)
else:
    p = 0
    for val in S:
        if val % 10 != 0:
            p = val
            break
    if p != 0:
        print(tot - p)
    else:
        print(0)
