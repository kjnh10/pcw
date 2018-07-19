n,m = map(int,input().split())
cou = 0
lis = []
for i in range(n):
    lis.append(int(input()))
lis.sort()
m -= sum(lis)
cou += n
cou += m//lis[0]
print(cou)