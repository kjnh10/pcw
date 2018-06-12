import math

n = int(input(""))
blue = []
red = []
for i in range(0,n):
    blue.append(input(""))
m = int(input(""))
for i in range(0,m):
    red.append(input(""))
ans = 0
for i in range(0,n):
    temp = 0
    for str in blue:
        temp += 1 if blue[i] == str else 0
    for str in red:
        temp -= 1 if blue[i] == str else 0
    ans = max(ans,temp)
print(ans)