N = int(input())
NG = [int(input()) for _ in range(3)]

if N in NG:
    print("NO")
else:
    rec = [N]
    for _ in range(100):
        tmp = set()
        for n in rec:
            for i in range(1, 4):
                sub = n - i
                if sub == 0:
                    print("YES")
                    exit()
                if sub not in NG:
                    tmp.add(sub)
        rec = tmp

    else:
        print("NO")
