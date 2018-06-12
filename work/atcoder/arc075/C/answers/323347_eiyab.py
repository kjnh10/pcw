n = int(input())
ss = list(map(int, (input() for _ in range(n))))

full = sum(ss)
non0s = list(s for s in ss if s%10!=0)

if full%10!=0:
    print(full)
else:
    if len(non0s)==0:
        print(0)
    else:
        print(full - min(non0s))