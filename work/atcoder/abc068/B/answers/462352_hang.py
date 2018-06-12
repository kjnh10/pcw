from math import log

ans = 1

for i in range(1,int(input())+1):
    if int(log(i,2)) > int(log(ans,2)):
        ans = i

print(ans)
