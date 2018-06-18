lis = list(map(int,input().split()))
cou = 0
lis.sort()
while lis[2] - lis[0] > 1:
    lis[0] +=2
    cou += 1
    lis.sort()
if lis[0] == lis[1] and lis[1] == lis[2]:
    print(cou)
elif lis[1] == lis[2]:
    print(cou + 2)
else:
    print(cou + 1)