n = int(input())
a = list(map(int, input().split()))
nep = 0
par = 0
cet = 0
for x in a:
    if x % 2 != 0:
        nep += 1
    elif x % 4 != 0:
        par += 1
    else:
        cet += 1

last = 0
for i in range(n):
    if last == 0:
        if nep:
            nep -= 1
            last = 1
        elif par:
            par -= 1
            last = 2
        else:
            cet -= 1
            last = 0
        continue
    if last == 2:
        if par:
            par -= 1
            last = 2
        elif cet:
            cet -= 1
            last = 0
        else:
            print('No')
            exit(0)
        continue 
    if cet:
        cet -= 1
        last = 0
    else:
        print('No')
        exit(0)
print('Yes')
