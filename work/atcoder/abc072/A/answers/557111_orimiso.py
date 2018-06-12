temp = input().split(" ")
suna = int(temp[0])
time = int(temp[1])
ans = suna - time
if ans <= 0:
    ans = 0
print(ans)
 