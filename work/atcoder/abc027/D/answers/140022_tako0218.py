s = list(reversed(input()))
lis = []
cou = 0
for i in s:
    if i == "+":
        cou += 1
    elif i == "-":
        cou -= 1
    else:
        lis.append(cou)
lis.sort()
print(sum(lis[len(lis)//2:])-sum(lis[:len(lis)//2]))
