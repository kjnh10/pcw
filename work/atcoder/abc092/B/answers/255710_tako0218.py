n = int(input())
d,x = map(int,input().split())
cou = 0
for i in range(n):
    a = int(input())
    for k in range(d):
        if k % a == 0:
            cou += 1
print(cou+x)